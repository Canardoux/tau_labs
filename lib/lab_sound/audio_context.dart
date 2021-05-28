import 'dart:ffi';
import 'package:ffi/ffi.dart';
import 'package:path/path.dart' as p;
import 'lab_sound.dart';
import '../extensions/ffi_string.dart';


class AudioContext {
  final Pointer<Int32> pointer;
  final double initSampleRate;
  final int channels;
  final bool offline;

  // double get correctionRate => initSampleRate / 24000.0;

  double correctionTime(double time) {
    // return time * correctionRate;
    return time;
  }

  AudioHardwareDeviceNode? _device;
  AudioHardwareDeviceNode get device {
    _device ??= AudioHardwareDeviceNode.fromId(this, LabSound().AudioContext_device(this.pointer));
    return _device!;
  }

  setDevice(AudioNode node) {
    LabSound().AudioContext_setDeviceNode(this.pointer, node.nodeId);
  }

  AudioContext(
      {this.offline = false, this.initSampleRate = 44100.0, this.channels = 2, double? timeMills})
      : pointer = (offline
            ? LabSound().createOfflineAudioContext(channels, initSampleRate, timeMills!)
            : LabSound().createRealtimeAudioContext(channels, initSampleRate));

  double get currentTime {
    // return lab.currentTime(this.pointer) / correctionRate;
    return LabSound().AudioContext_currentTime(this.pointer);
  }

  double get predictedCurrentTime => LabSound().AudioContext_predictedCurrentTime(this.pointer);

  double get sampleRate {
    return LabSound().AudioContext_sampleRate(this.pointer);
  }

  int get currentSampleFrame {
    return LabSound().AudioContext_currentSampleFrame(this.pointer);
  }

  suspend() {
    LabSound().AudioContext_suspend(this.pointer);
  }
  resume() {
    LabSound().AudioContext_resume(this.pointer);
  }

  static AudioBus decodeAudioFile(String path, {autoDispose = true}) {
    return AudioBus(path, autoDispose: autoDispose);
  }

  startOfflineRendering(String filePath, RecorderNode recorder) {
    LabSound().AudioContext_startOfflineRendering(this.pointer, recorder.nodeId, filePath.toInt8());
  }

  // 音频渲染设备;
  AudioHardwareDeviceNode get destination => this.device;
  // AudioNode get destination => AudioNode(this, -1);

  /// 关闭一个音频环境, 释放任何正在使用系统资源的音频。
  dispose() {
    LabSound().AudioContext_releaseContext(this.pointer);
  }
}

# FreeNDroid 

Free + Android = FreeNDroid

Android'in kısıtlamalarından özgürleşmek için tasarlanmış,
AArch64 mimarisi üzerine inşa edilmiş minimal bir işletim sistemi.

## Hakkında

FreeNDroid, Android tabletlerde özgürce çalışabilen,
sıfırdan yazılmış bir OS projesidir.
Bootloader'dan kernel'e kadar her şey elle yazıldı.

## Kullanılan Teknolojiler

- AArch64 Assembly — Bootloader
- C — Kernel
- QEMU — Test ortamı

## Sürümler:

### v0.1 (Alfa)
- AArch64 Bootloader
- Minimal Kernel
- UART üzerinden konsol input/output
- QEMU'da çalışır

### v0.2 (Yeni sürüm)
- Bir-iki bug fixlendi
- Özel bir uyarı geldi
NOT: Yapımcı denemiştir ve GENEL olarak bir bug yaşanmamıştır.

## Nasıl Çalıştırılır?

### Gereksinimler
- Termux (Android)
- QEMU AArch64
- Clang

### Derleme
```bash
clang -target aarch64-none-elf -ffreestanding -nostdlib -c boot.S -o boot.o
clang -target aarch64-none-elf -ffreestanding -nostdlib -c kernel.c -o kernel.o
ld.lld -T linker.ld boot.o kernel.o -o freendroid.elf
Çalıştırma
qemu-system-aarch64 -M virt -cpu cortex-a53 -nographic -kernel freendroid.elf

Geliştirici:
Bir Çocuk - 11 yaşında, C ve AArch64 mimarili ASM falan biraz biliyor.

Lisans:
MIT License

Son Not:
Bu direkt bir işletim sistemi değildir. İçinde birkaç OS parçası barındırır.

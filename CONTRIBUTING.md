FreeNDroid'e Katkıda Bulunma Rehberi

Öncelikle katkıda bulunmak istediğin için teşekkürler!
FreeNDroid, herkesin geliştirebileceği açık bir proje. Aşağıdaki rehberi okursan süreci çok daha kolay atlarsın.

Zorunlu Bilgiler

FreeNDroid'e katkı yapmak için şu teknolojileri mutlaka bilmen gerekiyor:

- C — Kernel geliştirme
- AArch64 Assembly — Bootloader ve düşük seviyeli işlemler
- Linker Script (.ld) — Bellek düzeni

Bu konularda eksiksen önce biraz çalışmanı öneririz. Python veya diğer yüksek seviyeli diller bu projede **kullanılmıyor**.

Yol Haritası (Öncelik Sırasıyla)

Projeye şu sırayla özellik eklenmesi hedefleniyor:

1. Shell / Bash Desteği — Şu an en öncelikli
2. Dosya Sistemi
3. GUI / Dokunmatik Ekran Desteği
4. Ag Desteği

Geliştirme Ortamı

Başlamadan önce şunlara ihtiyacın var:

- Termux (Android) veya Linux bir sistem
- Clang — Derleme için
- QEMU AArch64 — Test için
- ld.lld — Linkleme için

Kurulum (Termux üzerinden):

pkg install clang qemu-system-aarch64 lld

Derleme ve Test

Derleme

clang -target aarch64-none-elf -ffreestanding -nostdlib -c boot.S -o boot.o
clang -target aarch64-none-elf -ffreestanding -nostdlib -c kernel.c -o kernel.o
ld.lld -T linker.ld boot.o kernel.o -o freendroid.elf

Çalıştırma

qemu-system-aarch64 -M virt -cpu cortex-a53 -nographic -kernel freendroid.elf

Katki Sureci

1. Repoyu fork'la
2. Yeni bir branch ac (git checkout -b ozellik/shell-destegi)
3. Degisikliklerini yap ve commit'le
4. Pull Request ac, ne yaptigini acikla

Kurallar

- Kod sade ve anlasilir olmali
- Her yeni ozellik QEMU'da test edilmis olmali
- Pull Request acarken ne ekledigini mutlaka acikla
- Saygili ve yapici ol

Lisans

Bu proje MIT Lisansi ile lisanslanmistir.
Katkilarinin da bu lisans kapsaminda oldugunu kabul etmis sayilirsin.

Gelistirici: Bir Cocuk — 11 yasinda

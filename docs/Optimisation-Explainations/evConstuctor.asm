DAddKeyPressEvent(Event*, int, bool, int&):       # @DAddKeyPressEvent(Event*, int, bool, int&)
        movsxd  rax, dword ptr [rcx]
        lea     rax, [rax + 4*rax]
        mov     dword ptr [rdi + 4*rax + 12], esi
        movsxd  rax, dword ptr [rcx]
        lea     rax, [rax + 4*rax]
        mov     dword ptr [rdi + 4*rax + 4], 4
        movsxd  rax, dword ptr [rcx]
        lea     rax, [rax + 4*rax]
        mov     byte ptr [rdi + 4*rax + 16], dl
        movsxd  rax, dword ptr [rcx]
        lea     rax, [rax + 4*rax]
        mov     dword ptr [rdi + 4*rax], 0
        mov     eax, dword ptr [rcx]
        mov     edx, eax
        inc     edx
        movsxd  rdx, edx
        imul    rdx, rdx, -2139062143
        shr     rdx, 32
        add     edx, eax
        inc     edx
        mov     esi, edx
        shr     esi, 31
        sar     edx, 7
        add     edx, esi
        mov     esi, edx
        shl     esi, 8
        sub     edx, esi
        add     eax, edx
        inc     eax
        mov     dword ptr [rcx], eax
        ret
CAddKeyPressEvent(Event*, int, bool, int&):       # @CAddKeyPressEvent(Event*, int, bool, int&)
        movsxd  rax, dword ptr [rcx]
        lea     rax, [rax + 4*rax]
        movabs  r8, 17179869184
        mov     qword ptr [rdi + 4*rax], r8
        mov     byte ptr [rdi + 4*rax + 8], 0
        mov     dword ptr [rdi + 4*rax + 12], esi
        mov     byte ptr [rdi + 4*rax + 16], dl
        mov     eax, dword ptr [rcx]
        mov     edx, eax
        inc     edx
        movsxd  rdx, edx
        imul    rdx, rdx, -2139062143
        shr     rdx, 32
        add     edx, eax
        inc     edx
        mov     esi, edx
        shr     esi, 31
        sar     edx, 7
        add     edx, esi
        mov     esi, edx
        shl     esi, 8
        sub     edx, esi
        add     eax, edx
        inc     eax
        mov     dword ptr [rcx], eax
        ret
main:                                   # @main
        xor     eax, eax
        ret
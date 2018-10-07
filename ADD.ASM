dosseg
model small
.8086

.data
p1 db 41h
p2 db 01h
p3 db ?

.code
mov ax,@data
mov ds,ax

mov al,p1
add al,p2
mov p3,al

mov ax,4c00h
int 21h
end

 //mac's yuhua.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�껨��Ժ");
  set("long",@LONG
����Ϊ��ʿ��Ϣ����ʳ�������Ĵ����������徻���м���ʯ����
���ӣ��ڷ���һЩ�򵥵�ʳƷ�����ϣ�С����һ���Ͼ�����Ϊ�껨��
��˵�˵���̩ɽ����ʱ�ʵ����ù��ľ�ˮ���峺������
LONG
  );
  set("exits",([
         "east":__DIR__"peitian.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
    set("resource/water", 1);
    set("liquid/container", "�껨��"); 
  set("coor/x",300);
        set("coor/y",2300);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}       

 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����ɽ��´��������ɼ�������������������ϵķ������׳�
��κ���������������ϴ�Ƭƽ̹�����أ��ӵ����洦�ɼ�ש������
ˮ������ש��������͹��ŵĻ���ש���ߵ�������ƽ��������ʮ��
���Σ���������Ϊ�������Ρ�ȫ���ɻ�̨���������ܣ���ɲ����
�ں���ӡ�������֮�棬�Ѷ�֮���Ǿ��޽��еġ�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"fawang", 
  "east" : __DIR__"huishan",
  "southwest" : __DIR__"shuyuan",
]));
        set("objects", ([
                __DIR__"npc/amao" : 1,
       ]) );
        set("outdoors", "songshanfy");
        set("coor/x",-220);
        set("coor/y",420);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}   

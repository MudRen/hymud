 inherit ROOM;
void create()
{
        set("short", "��̨������");
        set("long", @LONG
վ��ɽ�嶥�ˣ�����ң������·�������֣���ʱƮ��������ס������ߡ���
�������������֣����¶����絶�����ɣ�������ɽ·ǧ���ٻأ�·�������ɳ��֣�
�羰���������һ��
LONG
        );
    set("exits", ([ 
        "southdown" : __DIR__"canglong",
        ]));
        set("objects", ([
                __DIR__"obj/tree" : 1,
                __DIR__"npc/baiyun" : 1,
        ]));  
    set("outdoors", "huashanfy"); 
    set("coor/x",-577);
    set("coor/y",-88);
    set("coor/z",-73);
        setup();
    replace_program(ROOM);
}  

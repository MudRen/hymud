 inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
�·嶥��ԭ��ƽ̹�����к��������嶥����̨��̨�Ͻ�����ͤһ����ͤ���ù�
Χ��һ�̡�̨�治���������֣�̽ͷ��������ֻ��������������ãã���붫���
һ����ɽ��������
LONG
        );
    set("exits", ([ 
                "north" : __DIR__"yaozi",
        ]));
        set("objects", ([
                __DIR__"npc/gongye.c" : 1,
                    __DIR__"npc/crow.c" : 1,
       ]) ); 
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-566);
    set("coor/y",-100);
    set("coor/z",73);
        setup();
    replace_program(ROOM);
}  

 inherit ROOM;
void create()
{
        set("short", "��ջ��");
        set("long", @LONG
�±��ƴ�ֱ��Ȼ�������ɽ����ȴ����һ��ջ����ľ׮����ȭͷ���С��ʯ
���ڣ������̼���ľ�壬���������߲������˲�����С����¿�������һƬ��
�̣�Ϫ���ݺᣬ��ɫ���ˡ���ǰ�������ٹ��£�ˮ����¡������׳�ۡ� 
LONG
        );
    set("exits", ([ 
                "south" : __DIR__"changpu",
        ]));
        set("objects", ([
                __DIR__"obj/yabi" : 1,
                __DIR__"npc/chiyang" : 1,
        ]) );   
    set("outdoors", "huashanfy"); 
    set("coor/x",-565);
    set("coor/y",-25);
    set("coor/z",20);
        setup();
    replace_program(ROOM);
}  

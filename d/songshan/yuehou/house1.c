// /d/yuehou/house1.c

inherit ROOM;

void create()
{
        set("short", "��լ");
        set("long", @LONG
�������������һ����լ������ס��һ���ˣ�����ÿ�����
�ɻ���Ӻͺ����ڼ��ź����ˡ�����������С����м���
LONG
        );

       set("exits", ([
                "north"             : __DIR__"troad3",
]) );

       set("light_up",1);

       setup();
       replace_program(ROOM);
}


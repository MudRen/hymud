// Room: /d/snow/mill.c
inherit ROOM;
void create()
{
        set("short", "ĥ��");
        set("long", @LONG
������һ����ĥ���Ϊҵ��ĥ����������һ���Ŀռ䱻һ��
ˮ��ռ�ݣ�ˮ��ת����������ϵ�ľ�ᣬľ���ƶ���������ת����
�������ʯĥ�����ӵ���һ�Ƕѷ���һЩ�յ������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"lane2",
]));
        setup();
        replace_program(ROOM);
}

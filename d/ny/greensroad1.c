// Room: /d/snow/sroad1.c

inherit ROOM;

void create()
{
        set("short", "��Զ�ǽֵ�");
        set("long",
"��������Զ�ǵĽֵ���������һ�����ֵĹ㳡���ϱ�����С·ͨ��һ�����ۣ���������һ��\n"
"С������ɽ��ͨ��ɽ�ϣ�������һ���Ƚ�խ�Ľֵ����β�������֮�䴫������Ȯ�͡�\n"
);
        set("exits", ([ /* sizeof() == 4 */
]));
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}

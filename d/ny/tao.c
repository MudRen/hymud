
// Room: /d/snow/tao.c

inherit ROOM;

void create()
{
        set("short", "éɽ����");
        set("long",
"����һ����ɭ�ĵ��ۣ�������ǰ�������Ϲ��������������,һλò�����˵ĵ�ʿ��������\n"
"�����ǳ������ġ�\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"eroad3",
]));

        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}

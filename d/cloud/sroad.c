
// Room: /u/cloud/dragonhill/sroad.c

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long",
"������ѩͤ��ͨ�������ıؾ�֮·�������������򣬱���ͨ�������ڡ����ȹٸ����ڴ�\n"
"������·�����������ε������ޣ������������ϳ���ǿ�˳�û��ֻ�����ա���˵����·��\n"
"�ɹ������˺ܶ࣬·���ѱ��ȵú�ƽ�ˡ�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"shillfoot",
  "southeast" : __DIR__"entrance"
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

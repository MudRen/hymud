inherit ROOM;
void create()
{
        set("short", "����ɽׯ");
        set("long",
"��ʱ��ɫ�Ѱ���ׯ���ѿ���ֻ�������ƾɵ�ׯԺ�������󣬲�֪����\n"
"����ֹ��ǰ��һ�������������ѱ���ѩ�����ǣ�һ·ͨ��ׯԺ��\n"
);
        set("no_magic", "1");

        set("exits", ([ /* sizeof() == 2 */
          "north" : __DIR__"yongdao2",
          "south" : __DIR__"gate",
        ]));
        setup();
}


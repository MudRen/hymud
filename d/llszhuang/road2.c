inherit ROOM;
void create()
{
        set("short", "ƽԭ·");
        set("long",
"��������򶫣����ƽ�ƽ��·������Сʯ�ӣ��������ȥ��������Ϊ\n"
"�ѽš������Ե���ľԽ��Խ�٣������ƻ����������Ҹ��ط���Ϣһ�£�\n"
"����ǰ���м�С�ƹݡ�\n"
);
        set("exits", ([
  "east" : __DIR__"road1",
  "northwest" : __DIR__"inn",
]));
        set("outdoors", "llszhuang");
        setup();
}


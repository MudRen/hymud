inherit ROOM;
void create()
{
        set("short", "ɽ�ȿ�");
        set("long",
"·������һ��ʯ��������д��������׭�֣���������ɽ�ȿ�ȥ��һ��\n"
"����������С·������ڣ�һΣ�´��жϿ���\n"
);
        set("exits", ([
            "out" : "/d/lingjiu/jian",
           "westup": __DIR__"road1",
]));
        set("outdoors","llszhuang");
        setup();
}


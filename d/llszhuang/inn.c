inherit ROOM;
void create()
{
        set("short", "����Сջ");
        set("long",
"���Ƿ��ֶɿ��Աߵ�һ��С�Ƽң����õľ����ڱ����з��衣�����\n"
"·ͨ�����������Ժ�һʱ������ɽׯ���Դ�����ɽׯ����Ѷ���￪ȥ֮��\n"
"����ͱ�÷ǳ������ˡ�ֻ��Ҫȥ����ɽׯ̽���������˲Ż�������ȵ�\n"
"�ƣ�׳һ׳�������㾫��\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "north" : __DIR__"dukou",
          "southeast" : __DIR__"road2",
        ]));
        set("objects", ([
            "/d/city/npc/xiaoer2" : 1,
        ]));
        setup();
}


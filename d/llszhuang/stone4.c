inherit ROOM;
void create()
{
        object ob;
        object table;
        set("short", "ʯ��");
        set("long",
"�������ţ��ص��к�Ȼ�����˵ƹ⡣ǰ���ұڣ��ѱ����ʯ�Ƶ�ģ��\n"
"�����ﾹ��ʮ����֮�࣬�������ӡ�ʯ����һֱ����ʪ���������һ��\n"
"ʯ��������һ��ʯ��������ʯ�ʡ�\n"
);
        set("no_magic", "1");
        set("exits",([
                "out" :__DIR__"shishi",
        ]) );
        set("objects",([
                __DIR__"npc/kuangren1" : 1,
        ]) );
        setup();
}


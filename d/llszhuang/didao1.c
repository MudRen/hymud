inherit ROOM;
void create()
{
        set("short", "�ص�");
        set("long",
"������ĵص����㲻֪��Ҫ����ò��ܳ�ȥ���·�ǰ����Щ���⡣��\n"
"ͷ����ȴ��������ȥ��·��\n"
);
        set("exits", ([
  "westup" : __DIR__"didao2",
]));
        set("no_magic", "1");
        setup();
}


 inherit ROOM;
void create()
{
        set("short", "�Ʒ���");
        set("long", @LONG
һ�䶫�������С�ݣ��������������õ��ư�ʣ����ϵ�ϲ��д���������ſ���
���ſ�����˳�ۣ�ǽ�����ŵĲ���ү���õ�����һ����������
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"inn",
        ]));
        set("objects", ([
                "/clone/npc/man" : 2,
                 __DIR__"npc/kiddo" : 1, 
        ]) );
        set("coor/x",30);
        set("coor/y",12060);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}        

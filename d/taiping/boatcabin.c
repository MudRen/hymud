 // seaside.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������⣬�����ھ����ĵ񻨴����ϡ�����������һ�Ŵ���һ�ſ������
�ǳ���������Ĵ����϶б�����˯��һ����ȫ�����ŵ�Ů����ϸ������֫��������
�����ȣ�һ˫�鷿�������������紺�Ļ��٣������������������ˡ����ߵ�̴ľ��
�Ϸ�����ϺƬ���ŵķ��ź�һ���ơ�
LONG
        );
        set("exits", ([ 
                "out":  __DIR__"boatbow",
        ]));
        set("objects", ([
        __DIR__"npc/longwang" : 1,
        __DIR__"npc/longnu": 1,
        __DIR__"obj/table": 1,
                        ]) ); 
        set("item_desc", ([
                "��": "һ�ſ�������ǳ���������Ĵ���\n",
                "bed": "һ�ſ�������ǳ���������Ĵ���\n",
         ]));
        set("coor/x",1020);
        set("coor/y",-220);
        set("coor/z",-10);
        setup();
}   
void reset()
{
        object table,item1;
        ::reset();
        table = present("table", this_object());
        
        if (!present("rice",table)){
                item1 = new(__DIR__"obj/ricecake");
                item1->move(table);
                }
}

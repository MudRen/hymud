 inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�ɸɾ���������϶�������ѩɽׯ���书���š���Щ�����Ƕ��鵶������
�Ͷ��齣��ѩ���������Ѫ�Ľᾫ��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"back_yard",
])); 
       set("objects", ([
                __DIR__"obj/book1" : 1,
                __DIR__"obj/book2" : 1,
                __DIR__"obj/book3" : 1,
                __DIR__"obj/book4" : 1,
                __DIR__"obj/book5" : 1,
                __DIR__"obj/book6" : 1,
                 __DIR__"obj/shelf" : 1, 
        ]) );
//      set("refresh_all_items", 1);
        set("coor/x",-1220);
        set("coor/y",70);
        set("coor/z",-10);
        setup();
}     

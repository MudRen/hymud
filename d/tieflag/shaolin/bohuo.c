 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        object con, ob;
        set("short", "�����");
        set("long", @LONG
���������ղ˵ĵط���������ɮ�����ڴ�����ղˣ���������С
�����ɣ�����Ĳ����ո����ɺʹ���гԵģ���ΪѰ��ɮ�ˣ���Ʒ����
��ֻ�л�¸һ�£���˵��Щ���ж�������ҩ�ģ�������������档����
�ٽ���ѧ��Ϊ��
LONG
        );
        set("exits", ([ 
 "south" : __DIR__"qianzao",  
]));
        set("objects", ([
                __DIR__"npc/monk5_sentry" : 2,
       ]) ); 
        set("resource/water", 1);
        set("liquid/container", "���");   
        set("coor/x",-230);
        set("coor/y",310);
        set("coor/z",60);
        setup();
        con = new(__DIR__"obj/xiaoguo");
        ob  = new(__DIR__"obj/bupin");
        if(ob && con) {ob->move(con); con->move(this_object());}
        con = new(__DIR__"obj/xiaoguo");
        ob  = new(__DIR__"obj/bupin");
        if(ob && con) {ob->move(con); con->move(this_object());}
        con = new(__DIR__"obj/xiaoguo");
        ob  = new(__DIR__"obj/bupin");
        if(ob && con) {ob->move(con); con->move(this_object());} 
}     

 // �ص�
inherit ROOM;
void create()
{
        set("short", "�ص�");
        set("long", @LONG
ǰ�����ڳ���һ�������������ĵص��ߵ��˾�ͷ
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"didao",
  "westdown" : __DIR__"qianfo/shanjiao",
]));
        set("coor/x",30);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if( userp(me) && dir == "eastup" )
                    message_vision("$N�ֽŲ��ã���ص����ȥ\n",me); 
        return 1;
} 

 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "С����");
        set("long", @LONG
��Ȼ���Ǳ�Զ��һ��С�򣬿��ǵ��аټ�ʮ���˼ң���ª�Ŀ�ջ��С����Ҳ��
�ü��ң���������׼����Щ��������ҹ��·������ʳ��֮���������Ĺ��ߣ�������
���������Ҳ�ֲ�����Ψ������Ĳ��������·�������֡�
LONG
        );
        set("exits", ([ 
        "south": __DIR__"road4",
        ]));
        set("objects", ([
                __DIR__"npc/bossding":  1,
                __DIR__"obj/table": 1,

        ]) );
        set("coor/x",-1130);
        set("coor/y",190);
        set("coor/z",0);
        setup();

}    
void reset()
{
        object          *inv;
        object          con, item;
        int             i; 
        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 6) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/hot_greens");
                item->move(con);
                item = new(__DIR__"obj/rice");
                item->move(con);
                item = new(__DIR__"obj/hot_rice");
                item->move(con);
                item = new(__DIR__"obj/hot_soup");
                item->move(con);
                item = new(__DIR__"obj/vege");
                item->move(con);
        }
}     

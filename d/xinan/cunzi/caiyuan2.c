//writen by lnwm
//caiyuan2.c

inherit ROOM;
void create()
{
    set("short", "菜园");
    set("long", @LONG
菜园中的菜地里种满了各种蔬菜。每一种都长势喜人，显然有人精心
照顾。地垄之间还有人工开垦的小渠，半尺深的渠水流淌而过，灌溉着每
一棵幼苗。土壤黑而酥松，显然很适于庄稼生长。
LONG
        );
    set("exits", ([ 
                "northeast"     :       __DIR__ "lroad3",
        ]));
    set("item_desc", ([
                "菜地"  :        "菜地里种满了各种各样的蔬菜，有翠绿的豌豆，青青的萝卜，
                                  红红的红辣椒，你忍不住想摘点下来\n",

        ]) );
    set("outdoors","lnwm");
    setup();
}

void init()
{
        add_action("do_chop","zhai");
        add_action("do_chop","pull");
        add_action("do_chop","摘");
}

int do_chop(string arg)
{
    object me;
        object vege;
    if(!arg || arg=="")
    {
        write("你要摘什么？\n");
        return 1;
    }
    if( arg == "萝卜" || arg == "luob" )
    {
        if((int) query("pluob") <= 3)
        {
                me = this_player();
        message_vision("$N从地里拔出了一只大萝卜\n", me);
                vege = new(__DIR__"obj/luob");
                vege->move(this_player());
                add("pluob",1);
                return 1;
                }
                else
        write("萝卜已经被人拔光了\n");
        return 1;
    }
    else if( arg == "豌豆" || arg == "wandou" )
    {
        if((int) query("pwandou") <= 10)
                {
                me = this_player();
        message_vision("$N从地里摘了一颗豌豆\n", me);
                vege = new(__DIR__"obj/wandou");
                vege->move(this_player());
                add("pwandou",1);
                return 1;
                }
                else
        write("豌豆已经被人摘光了\n");
        return 1;
    }
    else if( arg == "辣椒" || arg == "红辣椒" || arg == "lajiao" )
    {
        if((int) query("plajiao") <= 10)
                {
                me = this_player();
        message_vision("$N从地里摘了一只大红辣椒\n", me);
                vege = new(__DIR__"obj/lajiao");
                vege->move(this_player());
                add("plajiao",1);
                return 1;
                }
                else
        write("辣椒已经被人摘光了\n");
        return 1;
    }
    else
    {
        write("你不可以摘"+arg+"\n");
        return 1;
    }
}
        
void reset()
{
        :: reset();
        delete("plajiao");
        delete("pluob");
        delete("pwandou");
}


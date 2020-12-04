inherit ITEM;

mapping places=([
"bt" : "/d/baituo/dating.c",
"tam": "/d/beijing/tian_anm.c",
"gc" : "/d/city/guangchang.c",
"lj" : "/d/lingjiu/damen.c",
"sl" : "/d/shaolin/guangchang1.c",
"wd" : "/d/wudang/sanqingdian.c",
"xy" : "/d/xiaoyao/qingcaop.c",
"xx" : "/d/xingxiu/xxh2.c",
"hs" : "/d/huashan/square.c",
"xs" : "/d/xueshan/dadian.c",
"kl" : "/d/kunlun/shanmen.c",
"ny" : "/d/nanyang/nanyang.c",
"qz" : "/d/quanzhou/zhongxin.c",
"cd" : "/d/city3/guangchang.c",
"ca" : "/d/changan/ca.c",
"dl" : "/d/dali/wangfugate.c",
"wdj": "/d/wudujiao/dating.c",
"em" : "/d/emei/hcaguangchang.c",
"mj" : "/d/mingjiao/square.c",
]);

void create()
{
       set_name("江湖车马票", ({ "trans site","site"}) );
    set_weight(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
            set("long",
        "\n这是一张江湖车马票，以它的效力可以到达(trans)的地方：\n\n"
        "   gc : 扬州广场     tam : 天安门     bt : 白驼山\n"
        "   lj : 灵鹫宫       sl  : 少林寺     wd : 武当山\n"
        "   xy : 逍遥派       xx  : 星宿海     xs : 雪山寺\n"
        "   hs : 华山         ny  : 南阳       qz : 泉州  \n"
        "   kl : 昆仑         wdj : 五毒教     cd : 成都  \n"   
        "   dl : 大理         ca  : 长安       em : 娥眉  \n"
        "   mj : 明教                                   \n\n"

"set msg_min <anything>        设定当使用江湖车马票到达某处时, 别人所看到的讯息。\n"
"set msg_mout <anything>       设定当使用江湖车马票离开时, 原来房间里的人所看到的讯息。\n\n"

        );
            set("unit", "张");
    }
    setup();
}
void init()
{
    if ( !this_player()->is_ghost() )
    add_action("do_trans","trans");
}
int do_trans(string arg)
{
        object me,room,ob,*obj;
    string msg;
        int i;
    me=this_player();

    if( ! environment()->is_character() ) return 0;
    if (me->query("age")>22 && !wizardp(me))     return notify_fail("这只适合小孩子使用。\n");
    if( !arg ) return notify_fail("你要去哪里？\n");
    if (me->is_fighting())
         return notify_fail("战斗中无法使用车马票！\n");
    if  (!environment(me)->query("outdoors"))
         return notify_fail("在房间里面无法使用车马票！\n");
    if (!stringp(places[arg]))  return notify_fail("你要去哪里？\n");
    if (present("biao yin",me)) return notify_fail("你身上带着镖银，无法使用车马票！\n");
     if (present("jin he",me)) return notify_fail("你身上带着锦盒，无法使用车马票！\n");

     obj=deep_inventory(me);
     for (i=0;i<sizeof(obj);i++)
           if (obj[i]->id("illicit salt"))
         return notify_fail("你身上带着私盐，无法使用车马票！\n");

    ob=first_inventory(me);
    while(ob){
        if (ob->is_character() && !ob->is_corpse() )
            return notify_fail(ob->name()+"不能和你一起使用！\n");
        ob=next_inventory(ob);
    }
    if( stringp(msg = me->query("env/msg_mout")) )
       {if (msg!="") message_vision(msg+"\n", me);}
    else
        message_vision("$N叫了一辆马车，飞驰而去。\n", me);
    if (!room=find_object(places[arg]) )
        room=load_object(places[arg]);
    me->move(room);
    if( stringp(msg = me->query("env/msg_min")) )
       {if (msg!="") message_vision(msg+"\n", me);}
    else
        message_vision("$N跳下了马车，拍了拍身上的泥土。\n", me);
    me->receive_damage("jing", 10);
    return 1;
}
void owner_is_killed() { destruct(this_object()); }


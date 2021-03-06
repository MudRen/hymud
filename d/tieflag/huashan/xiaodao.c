 inherit ROOM;
void create()
{
        set("short", "山间小道");
        set("long", @LONG
这一段路地势平缓，四周山峦拔地而起，小路在山间谷地盘环而行，小路两侧
草木茂密，你不时听到树上黄雀悦耳的叫声，一条小溪流伴在小路的一侧缓缓向东
流去，溪水清澈见底。北方是一片茂密的树林。
LONG
        );
    set("exits", ([ 
                "westup" : __DIR__"canglong",
            "eastup" : __DIR__"xiaodao1",
                "north" : __DIR__"milin",
        ]));
    set("objects", ([
                __DIR__"npc/woodcutter2" : 1,
        __DIR__"npc/yellowbird" : 1,
    ]));
    set("outdoors", "huashanfy"); 
    set("coor/x",-573);
    set("coor/y",-90);
    set("coor/z",67);
        setup();
} 
void init(){
        if(this_player()->query("marks/华山_黄雀") && random(20)==0) {
                call_out("bird_come", 2, this_player());
        }
}
void bird_come(object me){
        object obj;
        int i;
        
        if(!interactive(me) || environment(me) != this_object()){
                return;
        }
        obj = new("/d/wolfmount/npc/obj/zhuguo");
        i =random(20);
   if(objectp(obj) && (i == 3 || i == 4)){
                message_vision("\n一只小黄雀飞落在$N肩膀，嘴里叼着一棵朱红色的果子。\n", me);
                message_vision("朱红色的果子落下，刚好落入$N怀中。小黄雀展翅高飞冲入云霄。\n", me);
                obj->move(me);
        } else {
                obj = new(__DIR__"obj/yihua");
                message_vision("\n一只小黄雀围绕着$N头顶飞了几圈，最后落到$N肩膀。\n", me);
                message_vision("一朵小花从小黄雀口中落下，掉入$N怀中。小黄雀叫了两声展翅飞去。\n", me);
                obj->move(me);
        }
        me->delete("marks/华山_黄雀");
}  

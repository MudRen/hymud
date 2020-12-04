#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "����ɳѨ");
        set("long", @LONG
������һ�������ܶ������ܺںڵģ���Լ���Կ�����Χ��ʯ�ܲ���������һ��
��������һ�����Ӵ�����������Լ��������ˮ������˵������Ȼ�����Լ��
ֻ��Ϊ�ڽ������һ�㰵��Ĺ�â���������������ĵ�ɳˮ����
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"sandriver1",
        "up" : __DIR__"dongd1",
        ]));
        set("no_fly",1);
//      set("no_curse",1);
        set("objects", ([
//              __DIR__"npc/sand_dragon" : 1,
        ]) );
        set("indoors", "quicksand");
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        set("dragon_death",0);
        setup();
} 
int valid_enter(object me) {
        tell_object(me, HIR"\n������һ�꣬�Ծ��ط��֣����ﾹȻ��һ���޴�Ŀն���
���ܹ�ʯ��ᾣ�����һ�ֲ���֮�С� \n\n"NOR);
        me->set_temp("out_river", time());
        return 1;
} 
void tell_exit(){
        object *inv, room;
        int j;
    
        room = find_object(__DIR__"dongd1");
        if(!objectp(room)) room = load_object(__DIR__"dongd1");        
        message("vision",HIY"�챦ʯ�����ĲӲӺ�����������˶�Ѩ���ں���ӳ���£��㿴��һ��ʯͷ
���ƺ���һ����ǡ�\n"NOR, this_object());
        inv = all_inventory(this_object());
        for(j=0; j<sizeof(inv); j++) {
                inv[j]->move(room);
        }
}   
void reset() {
        object dragon,new_dragon;
        
        ::reset();
        dragon=present("hibernating dragon",this_object());
        new_dragon=new("/d/quicksand/npc/sand_dragon");
        
        if (dragon)     return;
        
        if (!query("dragon_death")) {
                new_dragon->move(this_object());
                set("dragon_death",1);
                return;
        }
        
        if(query("dragon_death")+86400<time() && !random(4))
                new_dragon->move(this_object());
                
        return;
}
        
        
        
          

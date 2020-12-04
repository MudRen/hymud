 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM; 
int room_check(object room); 
void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
ˮ��ƽ������࣬�����ˮ�ʰ�͸����ε��ɫ�����˺�������ˮ���϶�������
���龰��ˮ��������������������ʱ�ι���С���������Բ���������ƺ������
�����޶����ԡ�
LONG
        );
        set("exits", ([
                "up" : __DIR__"yadi",
                "down": __DIR__"botsea",
        ]) );
        set("objects",([
                __DIR__"npc/octopus":   1,
        ]) );
        set("no_fly", 1);
        set("coor/x",190);
        set("coor/y",12310);
        set("coor/z",-70);
        setup();
} 
void init(){
        object me, obj;
        int htime,ntime;
        
        add_action("do_dive", "dive");
        me = this_player();
        if(userp(me) && !me->query_temp("appy/use_under_water")){
                 htime = me->query_str() + me->query_kar();
                if(!(ntime = me->query_temp("marks/ˮʱ")))   
                        ntime = 5;
                else 
                        ntime = ntime + 5;
                me->set_temp("marks/ˮʱ", ntime);
                call_out("airing", 5, this_player());
           }
}  
int do_dive(){
        object me, obj, room,octopus;
        me = this_player();
        obj = me->query_temp("armor/mask");
        
        if (octopus=present("octopus",this_object()))
                return notify_fail("�������צ���ɣ���ס�����ȥ·��\n");
        
        if(obj && obj->query("��ˮ")) {
                message_vision("$N��������Ǳȥ��\n", me);
                room = find_object(__DIR__"botsea");
                if(!objectp(room)){
                    room = load_object(__DIR__"botsea");
                }
                if (room_check(room)) {
                        tell_object(me,"����������ˣ�Ǳ����ȥҮ��\n");
                        return 1;
                }  else 
                        room->reset();
                me->move(room);
                this_object()->reset();
                message("vision", me->name() + "Ǳ������ߵ�ˮ�С�\n", environment(me), me);
        } else {
            tell_object(me, "������ؿ�Խ��Խ���ƣ����뾡�컻�����ˡ�\n");
    }
    return 1;
} 
int airing(object ob)
{
        int i, htime, ntime;
    
        if(ob->query_temp("apply/use_under_water")){
                return 1;
        }
        if(environment(ob) == this_object()){
        htime = (int)ob->query_str() + (int)ob->query_kar();
        if(!(ntime = (int)ob->query_temp("marks/ˮʱ"))) {  
                ntime = 5;
        } else {
                ntime = ntime + 5;
        }
        ob->set_temp("marks/ˮʱ", ntime);
        if( ntime > htime ) {
            ob->die();
            ob->set_temp("marks/ˮʱ", 0);
        }
        else if( ntime > (htime - 15) )
            message_vision(HIR "$N�Ѿ���óɰ����״̬���ٲ����Ͽ��ˮ���ͻ�����������\n"NOR, ob);
        else if( ntime > (htime - 30) )
            message_vision(HIR "$N�Ѿ���������࣬�����֮���ٲ���ˮ�����»�����������\n"NOR, ob);
        else 
            message_vision(HIB "$N�����ؿ�Խ��Խ�ƣ������ˮ���Ѵ����˺ܾá�\n"NOR, ob);
        
        call_out("airing",5, ob);
    }
    return 1;
} 
int valid_leave(object me,string dir){
        
        if (dir=="down"){
                tell_object(me,"ˮ���ļ������ʹ��Ǳ�������壩��ȥ���С�\n");
                return notify_fail("");
        }
        if(dir == "up") {
                me->delete_temp("marks/ˮʱ");
                message_vision("$N���˵���������ȥ��\n", me);
                return 1;
        }
}  
int room_check(object room) {
        int i;
        object *inv;
        
        inv=all_inventory(room);
        for (i=0;i<sizeof(inv);i++){
                if (userp(inv[i])) return 1;
        }
        return 0;
}   

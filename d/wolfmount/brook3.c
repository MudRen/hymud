#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "佻�Ϫ"); 
        set("long", @LONG
һ���峺���׵�Ȫˮ�����Ե�ɽ�н����������������д��ӵ��أ�����С����
������̣�����ɽ��������Ϫˮ�и�ɫ�ͷ׵Ļ�������Ϫˮ���������ʣ�һ������
�续��Ȫˮǳǳ���У��������ϣ��ɿ�����Զ���������ȪˮԴͷ�и�������
LONG); 
        set("type","waterbody");
        set("exits",([
                "south":__DIR__"sunlake",
                "northeast":__DIR__"brook",
        ]) );
       set("outdoors", "wolfmount");
        set("objects",([
                __DIR__"npc/xiaoma":1,
        ]) ); 
        set("coor/x",-750);
        set("coor/y",-750);
        set("coor/z",60);
        setup(); 
} 
void init(){
        object me;
        me = this_player();
        if(!me->query("imbue/xiaoma") && me->query("marks/ɱ̫��ʹ��") && present("xiao ma", this_object())) {
                if(me->query_temp("marks/wolf_xiaoma_good") ) {
                        call_out("imbue_event", 2, me, 0);
                } else if (me->query_temp("marks/wolf_xiaoma_normal")) {
                        call_out("imbue_event", 2, me, 1);
                }
        }
} 
void imbue_event(object me, int j){
        object xiaoma, weapon, obj, *inv;
        string prop;
        int i;
        if(!interactive(me) || environment(me) != this_object()){
           return 0;
        }
        xiaoma = present("xiao ma", this_object());
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }
        message_vision("\n$N��������$n�ı���һ������С�ӣ��ɵĺá��ı��顣\n", xiaoma, me);
        message_vision("$NͻȻ�����������˿ڳ���֮��$Nʹ������ֱ�У�����ĺ�ˮ��ર�વ�������������\n", xiaoma, me);
        if(!objectp(weapon)){
                if(objectp(obj)){
                        message_vision(HIR"\n������Ѫˮ�ĺ������$N��\n" + obj->name() + HIR"�ϣ��ֹ�����ϡ�\n"NOR, me);
                } else {
                        message_vision(HIR"\n������Ѫˮ�ĺ�������˵��ϡ�\n"NOR, me);
                }
        } else {
                message_vision(HIR"\n������Ѫˮ�ĺ������$N��" + weapon->name() + HIR"�ϣ�һת˲���ֻ�Ϊˮ�����ŵ���Ӱ���١�����\n"NOR, me);      
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                        if(j == 0 ) {
                                weapon->add(prop+"strength", 5);
                                weapon->add(prop+"tolerance", 5);
                                weapon->add(prop+"rigidity", 100);
                        } else if (j == 1) {
                                weapon->add(prop+"strength", 2);
                                weapon->add(prop+"rigidity", 50);
                        }
                        weapon->wield();
                } else {
                   if(j == 0 ) {
                                weapon->add(prop+"strength", 5);
                                weapon->add(prop+"tolerance", 5);
                                weapon->add(prop+"rigidity", 100);
                        } else if (j == 1) {
                                weapon->add(prop+"strength", 2);
                                weapon->add(prop+"rigidity", 50);
                        }
                }
                weapon->save();
                me->set("imbue/xiaoma", 1);
                me->save();
                return ;
        } 
        me->set("imbue/xiaoma", 2);
        me->save();
        return;
}       

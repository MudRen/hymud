#include <ansi.h>
#include <command.h> 
// inherit NPC; 
void time_greet(object ob);  
void shifting(object me) {
        
        object ob, start_room,end_room;
        mixed *current_time;
        string my_position, *type;
        int i;
        
        mapping shift_msg = ([
        "day_arrive"            : "$NЦ�Ǻǵ��߹���˵�������죬�����������á���\n",
        "day_leave"             : "$N�Ҵ�ææ���뿪�ˡ�\n",
        "night_leave"           : "$N̽ͷ���˿���ɫ���漴�������˳�ȥ��\n",
        "night_arrive"          : "$Nһ����������˹�����\n",
        "dinner_leave"          : "$N���˸�����˵�����Է���ʱ�䵽ඡ���\n",
        "dinner_arrive"         : "$N�߹�������������������\n",
        "after_dinner"          : "$N����������˸����ã��߳����š�\n",
        "back_dinner"           : "$N���ŷ������˹�����\n",
        ]);
                  
        ob=this_object();
        //current_time=NATURE_D->get_current_time();
        
        if( !me || environment(me) != environment() ) return;
        if (ob->is_fighting()) return; 
//      setting up default routine messages
        type=keys(shift_msg);     
        for (i=0;i<sizeof(type);i++) {
               if (this_object()->query("shift/"+type[i]))
                        shift_msg[type[i]]=this_object()->query("shift/"+type[i]);                               
        }       
        
        my_position=file_name(environment(ob)); 
//      check to see if the NPC has dinner routine
        if (ob->query("dinner_room")) {
                if (random(3)==0)
                if (my_position==ob->query("day_room")) {
                        start_room=environment(ob);
                   end_room=find_object(ob->query("dinner_room"));
                        if(!objectp(end_room)) 
                                end_room = load_object(ob->query("dinner_room")); 
                        message_vision(shift_msg["dinner_leave"],ob);
                        ob->move(end_room);
                        message_vision(shift_msg["dinner_arrive"],ob);
                        time_greet(ob);
                }
                if (random(3)==1)
                if (my_position==ob->query("dinner_room")) {
                        start_room=environment(ob);
                        end_room=find_object(ob->query("day_room"));
                        if(!objectp(end_room)) 
                                end_room = load_object(ob->query("day_room")); 
                        message_vision(shift_msg["after_dinner"],ob);
                        ob->move(end_room);
                        message_vision(shift_msg["back_dinner"],ob);
                        time_greet(ob);
                }
        } 
//      check to see if the NPC has night routine       
        if (ob->query("night_room"))  {
                if (random(3)==2)
                if (my_position==ob->query("day_room")) {
                        start_room=environment(ob);
                        end_room=find_object(ob->query("night_room"));
                        if(!objectp(end_room)) 
                                end_room = load_object(ob->query("night_room")); 
                        message_vision(shift_msg["night_leave"],ob);
                        ob->move(end_room);
                        message_vision(shift_msg["night_arrive"],ob);
                        time_greet(ob);
                }
        
                if (random(3)==1)
                if (my_position==ob->query("night_room")) {
                        start_room=environment(ob);
                        end_room=find_object(ob->query("day_room"));
                        if(!objectp(end_room)) 
                                end_room = load_object(ob->query("day_room")); 
                   message_vision(shift_msg["day_leave"],ob);
                        ob->move(end_room);
                        message_vision(shift_msg["day_arrive"],ob);
                        time_greet(ob);
                }
        } 
}  
void time_greet(object ob) {
        object *inv;
        int i;
        
        inv=all_inventory(environment(ob));
        if (sizeof(inv)<=1) return;
        for (i=0;i<sizeof(inv);i++){
                if (inv[i]==ob) continue;
                if (!inv[i]->is_character()) {
                        command("hmm "+inv[i]->get_id());
                        break;
                }
                command("greet "+inv[i]->get_id());
                break;
        }
        
}    

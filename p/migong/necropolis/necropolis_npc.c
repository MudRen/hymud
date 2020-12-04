#include <ansi.h>
inherit NPC;

int is_undead() {
	return 1;
}
    object get_object(string name) 
    { 
            object ob; 
            
            if (ob = find_object(name)) 
                    return ob; 
                     
           sscanf(name, "%s#%*s", name);  
            return load_object(name); 
     } 
void die() {
	object killer,*inv,item,mazeobj;
	int count,finished;
	string name;
	//death_msg
	if(query("death_msg"))
			message_vision(query("death_msg"),this_object());
	else
			message_vision("\n$N���ˡ�\n\n",this_object());
	//check quest
	killer = query_temp("last_damage_from");

	if(killer && userp(killer)) {
                //mazeobj = this_object();
                if(!mazeobj) mazeobj = killer;
                if(mazeobj->query("quest/to_kill/"+name())) {
                        count = mazeobj->query("quest/to_kill/"+name());
			finished = mazeobj->query("quest/killed/"+name());
			finished++;
			if(finished>count)
					finished = count;
			mazeobj->set("quest/killed/"+name(),finished);
			tell_object(killer,HIW"ɱ�� "+name()+": "+finished+"/"+count+"��\n"NOR);
		}
		//��6������������һ��ɱ��ʮ������
                if(mazeobj->query("quest/quest_index")==6 && is_undead() &&
                   environment() && environment()->query("short")==HIY"���鷨��"NOR) {
				count = mazeobj->query("quest/to_kill/����");
				if(count>0) {
					finished = mazeobj->query("quest/killed/����");
					finished++;
					if(finished>count)
						finished = count;
					mazeobj->set("quest/killed/����",finished);
					tell_object(killer,HIW"���� ����: "+finished+"/"+count+" ��\n"NOR);
				}
		}
	}
	//put all thing to ground
	inv = all_inventory(this_object());
	foreach(item in inv) {
		if(item)
			item->move(environment());
	}
	::die();
}

int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place, my_birth_place;
        object env; 
        string userid;
        int x,y;
         
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        env = environment(this_object());
        to_go_place = env->query("exits/"+direction);
        my_birth_place = file_name(this_object());
        
        //ccommand("say "+to_go_place);
        //if(sscanf(to_go_place,"/data/maze/%s/maze/%d/%d",userid,x,y)!=3)
                        //return 1;
        command("go " + direction);
        add_temp("random_move",1);
        return 1;
}   

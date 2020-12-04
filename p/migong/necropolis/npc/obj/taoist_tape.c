#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name("¼����", ({ "tape" }) );
        set_weight(2);
        set("no_get", 1);
        set("no_put", 1);
        set("value",10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "¼������\n");
                set("value", 1);
        }
        setup();
} 

void play_sound_0(object speaker,int index) {
	if(!environment())
		return;
	if(!speaker)
		return;
	switch (index)  {
		case(0):
			tell_room(environment(),CYN"��һ˵�������˵������幬���Ŷ��˷��ʦ��......\n"NOR);
			break;
		case(1):
			tell_room(environment(),CYN"��һ˵���������˴�Ĺ԰������䣬�Ҵ������µ������쿴��������������......\n"NOR);
			break;
		case(2):
			tell_room(environment(),CYN"��һ˵�������Ĺ԰�����һ�����鷨��������ѹ��һ���Ϲ�Ѫħ��\n"NOR);
			break;
		case(3):
			tell_room(environment(),CYN"��һ˵�����ҵȷ��֣����������Ѿ��ӷ��������ݣ�Ѫħ���������ļ���\n"NOR);
			break;
		case(4):
			tell_room(environment(),CYN"��һ˵���������������²��÷����ʱ��һȺ���ֺ���ɱ�˹�����\n"NOR);
			break;
		case(5):
			tell_room(environment(),CYN"��һ˵������Щ����һ�����ܵ���Ѫħ�����䣬ɥ�Ĳ����ˡ�\n"NOR);
			break;
		case(6):
			tell_room(environment(),CYN"��һ˵���������������˸����ܾ��ˣ����������������ң����ֻʣ��һ��������������......\n"NOR);
			break;
		case(7):
			tell_room(environment(),YEL"��һ���صĿ�����......\n"NOR);
			break;
		case(8):
			tell_room(environment(),CYN"��һ˵�������Ը������ǶԸ�Ѫħ��(accept yes/no)\n"NOR);
			speaker->set_temp("�����׽���",1);
			break;
		default: 
			speaker->delete_temp("in_speech");
			destruct(this_object());
			return;

	}
	call_out("play_sound_0",1,speaker,++index);
}

void play_sound_1(object speaker,int index) {
	object mazeobj;
	if(!environment())
		return;
	if(!speaker)
		return;
	switch (index)  {
		case(0):
			tell_room(environment(),CYN"��һ˵������......��л......\n"NOR);
			break;
		case(1):
			tell_room(environment(),CYN"��һ˵����Ѫħʵ���Ƿ����ޱ�......�����ó��ջ�......���Ѿ��ֲ�����ң�\n"NOR);
			break;
		case(2):
			tell_room(environment(),CYN"��һ˵����������֤����δ��Ѫħ�ջ�: ɱ�˸����ã��˸����飬�˸���ʬ��\n"NOR);
			break;
		case(3):
			tell_room(environment(),CYN"��һ˵������ɺ���������(report)��\n"NOR);
			speaker->set_temp("����",1);
			break;
		default: 
			//mazeobj = MAZE_D->query_maze_mainobj(speaker);
			if(mazeobj) {
				mazeobj->set("quest/maze_code","necropolis");
				mazeobj->set("quest/quest_index",1);
				mazeobj->set("quest/quest_name","֤���ҳ�");
				mazeobj->set("quest/quest_desc","ɱ�˸����ã��˸����飬�˸���ʬ");
				mazeobj->set("quest/quest_branch","taoist");
				mazeobj->set("quest/to_kill/����",8);
				mazeobj->set("quest/to_kill/����",8);
				mazeobj->set("quest/to_kill/��ʬ",8);
			}
			speaker->delete_temp("in_speech");
			destruct(this_object());
			return;
	}
	call_out("play_sound_1",1,speaker,++index);
}

void play_sound_2(object speaker,int index) {
	object mazeobj;
	if(!environment())
		return;
	if(!speaker)
		return;
	switch (index)  {
		case(0):
			tell_room(environment(),CYN"��һ˵������...���ò���!\n"NOR);
			break;
		case(1):
			tell_room(environment(),CYN"��һ˵������Ҫ��սѪħ, ��Ҫ�˽�Ѫħ������......\n"NOR);
			break;
		case(2):
			tell_room(environment(),CYN"��һ˵�������Ĺ԰�кܶ�Ѫħ������......����ÿ�����´���������һ��������\n"NOR);
			break;
		case(3):
			tell_room(environment(),CYN"��һ˵����ȥ������ɱ������������ʿ���������÷�ʦ����������֮�ۣ���������֮������Ѫ��ʬ��������ʬɷ��\n"NOR);
			break;
		case(4):
			tell_room(environment(),CYN"��һ˵������ɺ���������(report)��\n"NOR);
			speaker->set_temp("����",2);
			break;
		default: 
			//mazeobj = MAZE_D->query_maze_mainobj(speaker);
			if(mazeobj) {
				mazeobj->delete("quest/to_kill");
				mazeobj->set("quest/maze_code","necropolis");
				mazeobj->set("quest/quest_index",2);
				mazeobj->set("quest/quest_name","֤��ʵ��");
				mazeobj->set("quest/quest_desc","ɱ����������ʿ���������÷�ʦ��������ڤ֮�ۣ�������ڤ֮������Ѫ��ʬ������ʬɷ");
				mazeobj->set("quest/quest_branch","taoist");
				mazeobj->set("quest/to_kill/������ʿ",3);
				mazeobj->set("quest/to_kill/���÷�ʦ",3);
				mazeobj->set("quest/to_kill/��ڤ֮��",3);
				mazeobj->set("quest/to_kill/��ڤ֮��",3);
				mazeobj->set("quest/to_kill/Ѫ��ʬ",3);
				mazeobj->set("quest/to_kill/ʬɷ",3);
			}
			speaker->delete_temp("in_speech");
			destruct(this_object());
			return;
	}
	call_out("play_sound_2",1,speaker,++index);
}

void play_sound_3(object speaker,int index) {
	object mazeobj;
	if(!environment())
		return;
	if(!speaker)
		return;
	switch (index)  {
		case(0):
			tell_room(environment(),CYN"��һ˵�������úܺ�!\n"NOR);
			break;
		case(1):
			tell_room(environment(),CYN"��һ˵��������������ʵ���Ҿͷ����ˣ�\n"NOR);
			break;
		case(2):
			tell_room(environment(),CYN"��һ˵����ȥ�ҵ���Щ��������ֺ��У�ɱ�����ǡ����������и����������ԶԸ�Ѫħ��\n"NOR);
			break;
		case(3):
			tell_room(environment(),CYN"��һ˵������ɺ���������(report)��\n"NOR);
			speaker->set_temp("����",3);
			break;
		default: 
			//mazeobj = MAZE_D->query_maze_mainobj(speaker);
			if(mazeobj) {
				mazeobj->delete("quest/to_kill");
				mazeobj->set("quest/maze_code","necropolis");
				mazeobj->set("quest/quest_index",3);
				mazeobj->set("quest/quest_name","�ų��켺");
				mazeobj->set("quest/quest_desc","ɱ���ֺ��У�ȡ�÷���");
				mazeobj->set("quest/quest_branch","taoist");
				mazeobj->set("quest/to_kill/����",1);
				mazeobj->set("quest/to_find/������",1);
			}
			speaker->delete_temp("in_speech");
			destruct(this_object());
			return;
	}
	call_out("play_sound_3",1,speaker,++index);
}

void play_sound_4(object speaker,int index) {
	object mazeobj;
	if(!environment())
		return;
	if(!speaker)
		return;
	switch (index)  {
		case(0):
			tell_room(environment(),CYN"��һ˵����̫����!�ɶ�ĺ��У�������......����.....Ŷ...�Ǹ�...�ȿ�...\n"NOR);
			break;
		case(1):
			tell_room(environment(),CYN"��һ˵�����������鷨����ҪһЩ������ʢ�Ķ���Ϊ����\n"NOR);
			break;
		case(2):
			tell_room(environment(),CYN"��һ˵���������Ĺ��ȣ���ڤħ����ڤ֮�𣬽�ʬ���Ľ�ʬѪ����ȡһ������\n"NOR);
			break;
		case(3):
			tell_room(environment(),CYN"��һ˵������ɺ���������(report)��\n"NOR);
			speaker->set_temp("����",4);
			break;
		default: 
			//mazeobj = MAZE_D->query_maze_mainobj(speaker);
			if(mazeobj) {
				mazeobj->delete("quest/to_kill");
				mazeobj->delete("quest/to_find");
				mazeobj->set("quest/maze_code","necropolis");
				mazeobj->set("quest/quest_index",4);
				mazeobj->set("quest/quest_name","Ѱ�ҷ���");
				mazeobj->set("quest/quest_desc","�ҵ������Ĺ��ȣ���ڤħ����ڤ֮�𣬽�ʬ���Ľ�ʬѪ��һ��");
				mazeobj->set("quest/quest_branch","taoist");
				mazeobj->set("quest/to_find/����",1);
				mazeobj->set("quest/to_find/��ڤ֮��",1);
				mazeobj->set("quest/to_find/��ʬѪ",1);
			}
			speaker->delete_temp("in_speech");
			destruct(this_object());
			return;
	}
	call_out("play_sound_4",1,speaker,++index);
}

void play_sound_5(object speaker,object leader,int index) {
	object mazeobj;
	if(!environment())
		return;
	if(!speaker)
		return;
	if(!leader) {
		speaker->delete_temp("in_speech");
		destruct(this_object());
		return;
	}
	switch (index)  {
		case(0):
			tell_room(environment(),CYN"��һ˵��������������Ҫ�ķ�����ȫ�ˣ�\n"NOR);
			break;
		case(1):
			tell_room(environment(),CYN"��һ˵�������ǵ����鷨��������������������ٻ�...Ŷ�������·�ӡѪħ��\n"NOR);
			break;
		case(2):
			tell_room(environment(),CYN"��һ˵��������������ܻ���ЩѪħ������......���ǰ���·�ɣ�\n"NOR);
			speaker->set_temp("����",5);
			break;
		default: 
			//mazeobj = MAZE_D->query_maze_mainobj(speaker);
			if(mazeobj) {
				mazeobj->delete("quest/to_find");
				mazeobj->set("quest/maze_code","necropolis");
				mazeobj->set("quest/quest_index",5);
				mazeobj->set("quest/quest_name","������");
				mazeobj->set("quest/quest_desc","�Ѷ�һ�������鷨�󣬲����������Ѫħ����");
				mazeobj->set("quest/quest_branch","taoist");
				speaker->set_leader(leader);
			}
			speaker->delete_temp("in_speech");
			destruct(this_object());
			return;
	}
	call_out("play_sound_5",1,speaker,leader,++index);
}

void play_sound_6(object speaker,int index) {
	object mazeobj;
	if(!environment())
		return;
	if(!speaker)
		return;
	switch (index)  {
		case(0):
			tell_room(environment(),CYN"��һ˵�����ã��ҿ��Կ�ʼ�����ˣ�\n"NOR);
			break;
		case(1):
			tell_room(environment(),CYN"��һ˵������������Ҫ����ʮ��������ܷ������á���\n"NOR);
			break;
		case(2):
			tell_room(environment(),CYN"��һ˵��������ʩ���ڼ䣬���кܶ����鱻������������ɱ��ʮ����\n"NOR);
			break;
		case(3):
			tell_room(environment(),HIW"��һ�����ȡ���ڤ֮��ͽ�ʬѪͶ�뵽���鷨����...�����ʱ����������\n"NOR);
			break;
		case(4):
			tell_room(environment(),HIY"��һ�ó�����������������������......\n"NOR);
			speaker->set_temp("����",6);
			break;
		default: 
			//mazeobj = MAZE_D->query_maze_mainobj(speaker);
			if(mazeobj) {
				mazeobj->set("quest/maze_code","necropolis");
				mazeobj->set("quest/quest_index",6);
				mazeobj->set("quest/quest_name","��������");
				mazeobj->set("quest/quest_desc","������һ��ͬʱ�ھ��鷨��ɱ��ʮ������");
				mazeobj->set("quest/quest_branch","taoist");
				mazeobj->set("quest/to_kill/����",10);
				speaker->summon_undead(environment(),mazeobj);
				//speaker->start_call_out( (:call_other,speaker, "summon_undead",environment(),mazeobj :),5);
				//mazeobj->delete("quest/killed/����",20);
			}
			speaker->delete_temp("in_speech");
			destruct(this_object());
			return;
	}
	call_out("play_sound_6",1,speaker,++index);
}

void play_sound_7(object speaker,int index) {
	object mazeobj,*objs,obj,moon;
	if(!environment())
		return;
	if(!speaker)
		return;
	switch (index)  {
		case(0):
			tell_room(environment(),HIC"\n��һ˵�����ɰ��ڴ�һ�٣�\n\n"NOR);
			tell_room(environment(),BLINK HIC"\n������������գ����鷨�󷢳�ҫ�۵���ʹ�â��\n\n"NOR);
			objs = all_inventory(environment());
			foreach(obj in objs) {
				if(obj && obj->is_undead())
					obj->die();
			}
			break;
		case(1):
			tell_room(environment(),HIR"һ��Ѫɫ����Ӱ�Ӿ��鷨����Ư����Ͷ�뵽�������У�\n\n"NOR);
			break;
		case(2):
			tell_room(environment(),HIR"��һ�ջ��˾�������ֻ��Ѫɫ��Ӱ�Ͷ�һ�϶�Ϊһ��\n\n"NOR);
			break;
		case(3):
			tell_room(environment(),HIR"��һ��Ŀ��죬���Ĵ�Ц�������������ҳɹ��ˣ��ҳɹ��ˣ�\n\n"NOR);
			break;
		case(4):
			tell_room(environment(),HIR"��һ��Ц�����Ҷ�һ�����ھ���Ѫħ��Ѫħ�����ң�\n\n"NOR);
			break;
		case(5):
			tell_room(environment(),BLINK HIR"\n��һ��������������գ�ֻ����ʾ�Ȼ����һ��Ѫ��ɫ��������\n\n");
			moon = new("/p/migong/necropolis/obj/bloodmoon");
			moon->set("owner",speaker);
			moon->move(environment());
			environment()->set("short","���鷨��");
			objs = all_inventory(environment());
			foreach(obj in objs) 
					if(obj && userp(obj))
							obj->ccommand("look");
			environment()->set("short",HIY"���鷨��"NOR);
			moon->hurt();
			break;
		case(6):
			tell_room(environment(),HIR"\n\n��һ˵���������ǣ��������ұ������ǵ�ʱ���ˣ����ǰ����Ǳ��Ѫħ��һ���֣�������\n\n"NOR);
			speaker->set_temp("����",7);
			//mazeobj = MAZE_D->query_maze_mainobj(speaker);
			if(mazeobj) {
				mazeobj->set("quest/maze_code","necropolis");
				mazeobj->set("quest/quest_index",7);
				mazeobj->set("quest/quest_name","�ս�Ѫħ");
				mazeobj->set("quest/quest_desc","ɱ����ΪѪħ�Ķ�һ");
				mazeobj->set("quest/quest_branch","taoist");
				mazeobj->set("quest/to_kill/��һ",1);
			}
			speaker->set("attitude","aggressive");
			speaker->set("bellicosity",50000);
			speaker->set("kee",speaker->query("max_kee"));
			speaker->set("eff_kee",speaker->query("max_kee"));
			speaker->set("gin",speaker->query("max_gin"));
			speaker->set("eff_gin",speaker->query("max_gin"));
			speaker->set("sen",speaker->query("max_sen"));
			speaker->set("eff_sen",speaker->query("max_sen"));
			objs = all_inventory(environment());
			foreach(obj in objs) 
					if(obj && obj->is_character() && !obj->is_corpse() && obj!=speaker && !obj->is_undead()) {
							speaker->kill_ob(obj);
							obj->kill_ob(speaker);
					}
			
			speaker->delete_temp("in_speech");
			destruct(this_object());
			return;
			break;

	}
	call_out("play_sound_7",1,speaker,++index);
}

void play_sound_8(string dir,int index) {
	if(!environment())
		return;

	switch (index)  {
		case(0):
			tell_room(environment(),HIM"\n��һ�������ⲻ���ܣ�Ѫħ������Ѫħ��\n\n"NOR);
			tell_room(environment(),HIM"\n��һ���������һ̲��Ѫ��\n\n"NOR, this_object());
			call_out("play_sound_8",1,dir,++index);
			break;
		/*
		case(1):
			tell_room(environment(),HIY"��������һ���Ӻ���ʧ��\n"NOR);
			call_out("play_sound_8",60,dir,++index);
			break;
		case(2):
			MAZE_D->remove_maze(killer, "necropolis") 
			destruct(this_object());
			return;
			break;
		*/
	}
}
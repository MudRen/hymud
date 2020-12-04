#include <ansi.h> 
inherit "/p/migong/necropolis/necropolis_npc";

object m_mazeobj;
object get_mazeobj();
object *players = ({});

void set_players(object *ob) {
	players = ob;
}

void add_player(object ob) {
	if(member_array(ob,players)==-1) {
		players += ({ob});
		message_vision(BLU"$N��$n˵����лл��\n"NOR,this_object(),ob);
	} else
		message_vision(BLU"$N��$n˵�������Ѿ���Ӧ��æ���㲻�ᷴ�ڰɣ�\n"NOR,this_object(),ob);
}

object* query_players() {
	players -= ({0});
	return players;
}

void smart_fight();

void create()
{
        set_name("��һ", ({ "ding yi","ding"}) );
        set("gender", "����" );
        //set("title", HIC "���幬"NOR);
        set("age", 80);
        set("str", 50);
        set("con", 120);
        set("dex", 22); 
        set("int", 50);
        set("class","shaolin");     
        set("long",
        ""
        );
        //set("force_factor", 150);
        set("auto_perform", 2); 
        set("max_qi", 8000000);
	set("eff_qi", 480000);        
        set("max_jing", 8500000);
        set("eff_jing",850000);
        set("neili", 8000000);
        set("max_neili", 4500000);
        set("max_jingli", 500000);
        set("combat_exp", 300000000);

         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 680);
	set_skill("force", 550);
set_skill("martial-cognize",800);
	set_skill("taiji-shengong", 680);
	set_skill("dodge", 850);
	set_skill("tiyunzong", 680);
	set_skill("unarmed", 800);
	set_skill("taiji-quan", 680);
	set_skill("parry", 800);
	set_skill("sword", 800);
	set_skill("taiji-jian", 680);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 680);
	set_skill("array",300);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 680);
	set_skill("juehu-shou", 680);
	set_skill("raozhi-roujian", 680);
	set_skill("wudang-mianzhang", 680);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 680);
	set_skill("shenmen-jian", 680);
	set_skill("yitian-zhang", 380);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
set("count",1);

        set_temp("apply/attack", 3000);
        set_temp("apply/defense", 3000);
        set_temp("apply/damage", 1500);
        set_temp("apply/unarmed_damage", 1500);
        setup();
        carry_object("/clone/weapon/sword");
        carry_object("/clone/cloth/cloth")->wear();
}  

int is_undead() {
	return 0;
}

void init()
{       
        object ob; 
        ::init();
        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer", "answer");
        add_action("do_accept", "accept");
        add_action("do_report", "report");
	add_action("do_help", "help");
} 

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( query_temp("�����׽���") || query_temp("��ʼ˵������") || query_temp("����") )
                return;
        message_vision(CYN "$N����������˵������λ" + RANK_D->query_respect(ob) +
                "��������һ����(answer yes/no)\n" NOR, this_object(), ob);
} 

int do_answer(string arg) {
	object ob;
	if(arg=="yes") {
		if(query_temp("in_speech"))
			return 0;
		if(present("tape",environment()))
			return 0;
		set_temp("��ʼ˵������",1);
		ob = new(__DIR__"obj/taoist_tape");
		ob->move(environment());
		ob->play_sound_0(this_object(),0);
	} else if(arg=="no") {
		message_vision(BLU"$N˵����˭���������ţ���ӷϻ���\n",this_player());
	} else
		return notify_fail("��Ҫ�ش�ʲô��\n");
	return 1;
}

int do_accept(string arg) {
	object ob,*team;
	if(!query_temp("�����׽���"))
		return 0;
	if(query_temp("����"))
		return 0;
	if(arg=="yes") {		
		if(present("tape",environment()))
			return 1;
		delete_temp("�����׽���");
		team = this_player()->query_team();
		if(!team || sizeof(team)==0)
			team = ({this_player()});
		set_players(team);
		ob = new(__DIR__"obj/taoist_tape");
		ob->move(environment());
		ob->play_sound_1(this_object(),0);
	}	
	else if(arg=="no") {
		delete_temp("�����׽���");
		delete_temp("��ʼ˵������");
		message_vision(BLU"$N˵����û�ô��������ҿɲ��ɣ�\n",this_player());
	}
	else
		return 0;
	return 1;
}

int do_help(string arg) {
	if(arg!="ding" && arg!="ding yi")
		return 0;
	add_player(this_player());
	return 1;
}

int do_report(string arg) {
	object mazeobj,ob,env,*obs;
	int quest_index,has_enemy;
	if(query_temp("in_speech"))
			return 0;
	mazeobj = this_player();
	//if(!mazeobj)
//			return 0;
	
	quest_index = mazeobj->query("quest/quest_index");
	switch(quest_index) {
			case(1):
				if(mazeobj->query("quest/killed/����")>=mazeobj->query("quest/to_kill/����") &&
					 mazeobj->query("quest/killed/��ʬ")>=mazeobj->query("quest/to_kill/��ʬ") &&
					 mazeobj->query("quest/killed/����")>=mazeobj->query("quest/to_kill/����")
					 ) {
					 	//mazeobj->delete("quest/to_kill");
					 	set_temp("in_speech",1);
					 	ob = new(__DIR__"obj/taoist_tape");
						ob->move(environment());
						ob->play_sound_2(this_object(),0); 
				} else 
						return notify_fail("����δ�������\n");
				break;
			case(2):
				if(mazeobj->query("quest/killed/������ʿ")>=mazeobj->query("quest/to_kill/������ʿ") &&
					 mazeobj->query("quest/killed/���÷�ʦ")>=mazeobj->query("quest/to_kill/���÷�ʦ") &&
					 mazeobj->query("quest/killed/Ѫ��ʬ")>=mazeobj->query("quest/to_kill/Ѫ��ʬ") &&
					 mazeobj->query("quest/killed/ʬɷ")>=mazeobj->query("quest/to_kill/ʬɷ") &&
					 mazeobj->query("quest/killed/��ڤ֮��")>=mazeobj->query("quest/to_kill/��ڤ֮��") &&
					 mazeobj->query("quest/killed/��ڤ֮��")>=mazeobj->query("quest/to_kill/��ڤ֮��")
					 ) {
					 	//mazeobj->delete("quest/to_kill");
					 	set_temp("in_speech",1);
					 	ob = new(__DIR__"obj/taoist_tape");
						ob->move(environment());
						ob->play_sound_3(this_object(),0); 
				} else 
						return notify_fail("����δ�������\n");
				break;
			case(3):
				if(mazeobj->query("quest/killed/����")>=mazeobj->query("quest/to_kill/����") &&
					 mazeobj->query("quest/finded/������")>=mazeobj->query("quest/to_find/������")
				 ) {
					 	//mazeobj->delete("quest/to_kill");
					 	//mazeobj->delete("quest/to_find");
					 	set_temp("in_speech",1);
					 	ob = new(__DIR__"obj/taoist_tape");
						ob->move(environment());
						ob->play_sound_4(this_object(),0); 
				} else 
						return notify_fail("����δ�������\n");
				break;
		 case(4):
				if(mazeobj->query("quest/finded/����")>=mazeobj->query("quest/to_find/����") &&
					 mazeobj->query("quest/finded/��ڤ֮��")>=mazeobj->query("quest/to_find/��ڤ֮��") &&
					 mazeobj->query("quest/finded/��ʬѪ")>=mazeobj->query("quest/to_find/��ʬѪ")
				 ) {
					 	//mazeobj->delete("quest/to_find");
					 	set_temp("in_speech",1);
					 	ob = new(__DIR__"obj/taoist_tape");
						ob->move(environment());
						ob->play_sound_5(this_object(),this_player(),0); 
				} else 
						return notify_fail("����δ�������\n");
				break;
		case(5):
				if(!query_leader()) {
					message_vision(BLU"$N��$n˵�����·�ɡ�\n"NOR,this_object(),this_player());
					set_leader(this_player());
					return 1;
				}
				env = environment(this_object());
				if(env->query("short") == HIY"���鷨��"NOR) {
						obs = all_inventory(env);
						has_enemy = 0;
						foreach(ob in obs) {
							if(ob && ob->is_undead()) {
								has_enemy = 1;
								break;
							}
						}
						if(has_enemy)
								return 0;
						set_leader(0);
						ob = new(__DIR__"obj/taoist_tape");
						ob->move(environment());
						ob->play_sound_6(this_object(),0); 
				} else
						return 0;
				break;
		case(6):
				if(mazeobj->query("quest/killed/����")>=mazeobj->query("quest/to_kill/����") 
				 ) {
					 	mazeobj->delete("quest/to_kill");
					 	set("last_quester",this_player());
					 	set_temp("in_speech",1);
					 	ob = new(__DIR__"obj/taoist_tape");
						ob->move(environment());
						ob->set("quest/quest_index",7);
						this_player()->set("quest/quest_index",7);
						ob->play_sound_7(this_object(),0); 
				} else 
						return notify_fail("����δ�������\n");
				break;
	
	}
	return 1;
}

void smart_action3()
{
        object target,me,*enemies;
        string msg;
        int damage = 0;
        mixed yourexp,myexp;
        
        me = this_object();
        if(is_fighting() && !me->is_busy()) {
	        enemies = query_enemy();
	        if(!enemies || sizeof(enemies)==0)
		        return;

	        target = enemies[random(sizeof(enemies))];
	        if(target) 
	        {	               		                
                        msg = HIG "$N�����૵��������ģ�����һ�ӣ����о�����ɫ��â����ʱ��Ϊ���ɣ�\n\n";
                        msg += HIC "һ���������$n��\n" NOR; 

	                yourexp = target->query("combat_exp",1);
	                myexp = me->query("combat_exp",1);
		          if( random(myexp)>yourexp) 
	                {
                                damage = 10000 + random(10000);
                                damage = damage + random(damage);       
             
                                msg +=  HIR "������͡���һ��������$p����͸��������ϳ�һ�������ĺ���������£�\n"NOR;
                                target->receive_damage("qi", damage, me);
                                target->receive_wound("qi", damage/3, me);
                        } else
                                msg += "������͡���һ��������$p����͸�������������Ϣ��������£�\n";
                                
		        message_vision(msg, me, target);
		        if (damage > 0)
		                COMBAT_D->report_status(target);
		        
		        msg = HIW "\nһ�Ű׹�����$n��\n" NOR;
	                yourexp = target->query("max_neili");
	                myexp = me->query("max_neili");
	                if( random(myexp + yourexp) > yourexp ) 
	                {
                                damage = 10000 + random(10000);
                                damage = damage + random(damage);       
             
                                msg +=  HIR "������͡���һ�����׹��$p����͸��������ϳ�һ�������ĺ���������£�\n"NOR;
                                target->receive_damage("qi", damage, me);
                                target->receive_wound("qi", damage/3, me);
                        } else		        
	                        msg += "������͡���һ�����׹��$p����͸�������������Ϣ��������£�\n";
		        message_vision(msg, me, target);
		        if (damage > 0)
		                COMBAT_D->report_status(target);
		        
		        msg = HIM "\nһ���Ϲ�����$n��\n" NOR; 
	                yourexp = target->query_skill("martial-cognize", 1);
	                myexp = me->query_skill("martial-cognize", 1);
	                if( random(myexp + yourexp) > yourexp ) 
	                {
                                damage = 20000 + random(20000);
                                damage = damage + random(damage);       
             
                                msg +=  HIR "������͡���һ�����Ϲ��$p����͸��������ϳ�һ���������߲ʹ�������������\n"
                                            "��ת�����ִ�$N����ע��$P�����ڣ�\n" NOR;
                                target->receive_damage("qi", damage, me);
                                target->receive_wound("qi", damage/3, me);
                        } else	        
                                msg += "������͡���һ�����Ϲ��$p����͸�������������Ϣ��������£�\n";
                        message_vision(msg, me, target);
		        if (damage > 0)
		                COMBAT_D->report_status(target);
	        }
        }
	return;
}

void smart_fight() {
	smart_action3();
}

int count_undead(object env) {
		object *obs,ob;
		int count;
		obs = all_inventory(env);
		count = 0;
		foreach(ob in obs) {
				if(ob && ob->is_undead())
					count++;
			}
		return count;
}


void summon_undead(object env,object mazeobj) {
	object *obs,ob;
	int i,j;
	string file;
	
	if(!env)
		return;
	
	if(!mazeobj)
		return;
	
	if(mazeobj->query("quest/quest_index")!=6)
		return;
	
	if(count_undead(env)>=5)  {
			start_call_out( (:call_other,__FILE__, "summon_undead",env,mazeobj :),20);
			return;
	}
	
	/*
	if(mazeobj->query("quest/killed/����")>=mazeobj->query("quest/to_kill/����")) {
			message_vision(BLINK HIC"\n������������գ����鷨�󷢳�ҫ�۵���ʹ�â��\n\n"NOR,this_object());
			obs = all_inventory(env);
			foreach(ob in obs) {
				if(ob->is_undead())
					ob->die();
			}
	}
	*/
	//message_vision(HIC"\n�������Ϲ⻪һ����һ���������˳�����\n\n"NOR,this_object());
	tell_room(env,HIC"\n�������Ϲ⻪һ����һ�����鱻���˹�����\n\n"NOR);
	i = random(100);
	if(i<5) {
		j = random(2);
		switch(j) {
			case(0):
				file = "/p/migong/necropolis/npc/skeleton_lich";
				break;
			case(1):
				file = "/p/migong/necropolis/npc/zombie_lord";
				break;
			/*case(2):
				file = "/p/migong/necropolis/npc/ghost_devil";
				break;*/
		}
	} else if (i<25) {
		j = random(2);
		switch(j) {
			case(0):
				file = "/p/migong/necropolis/npc/skeleton_mage";
				break;
			case(1):
				file = "/p/migong/necropolis/npc/zombie_blood";
				break;
		/*	case(2):
				file = "/p/migong/necropolis/npc/ghost_eye";
				break;*/
		}
	
	} else if (i<45) {
		j = random(2);
		switch(j) {
			case(0):
				file = "/p/migong/necropolis/npc/skeleton_fighter";
				break;
			case(1):
				file = "/p/migong/necropolis/npc/zombie_power";
				break;
	/*		case(2):
				file = "/p/migong/necropolis/npc/ghost_fire";
				break;*/
		}
	
	} else {
		j = random(2);
		switch(j) {
			case(0):
				file = "/p/migong/necropolis/npc/skeleton";
				break;
			case(1):
				file = "/p/migong/necropolis/npc/zombie";
				break;
		/*	case(2):
				file = "/p/migong/necropolis/npc/ghost";
				break;*/
		}
	}
		ob = new(file);
		ob->set("attitude","aggressive");
		ob->set("bellicosity",50000);
		ob->move(env);
		start_call_out( (:call_other,__FILE__, "summon_undead",env,mazeobj :),20);
}

object get_mazeobj() {
	if(!m_mazeobj)
		//m_mazeobj = MAZE_D->query_maze_mainobj(this_object());
	return m_mazeobj;
}

int accept_object(object me, object obj)
{
	object mazeobj;
	int quest_index;
	//if(!mazeobj=get_mazeobj())
			//return 0;
	quest_index = mazeobj->query("quest/quest_index");
	switch(quest_index) {
		case(3):
				if(obj->name()=="������" &&
				   obj->query("id") == "spirit tower") {
						mazeobj->set("quest/finded/������",1);
                                                command("pat "+me->query("id"));
                                                destruct(obj);
						return 1;
				}
				break;
		 case(4):
		 		if(obj->name()=="����" &&
                                   obj->query("id") == "bone staff") {
						mazeobj->set("quest/finded/����",1);
						command("pat "+me->query("id"));
						destruct(obj);
						return 1;
				}
				if(obj->name()=="��ڤ֮��" &&
				   obj->query("id") == "ghost fire") {
						mazeobj->set("quest/finded/��ڤ֮��",1);
						command("pat "+me->query("id"));
						destruct(obj);
						return 1;
				}
				if(obj->name()=="��ʬѪ" &&
				   obj->query("id") == "zombie blood") {
						mazeobj->set("quest/finded/��ʬѪ",1);
						command("pat "+me->query("id"));
						destruct(obj);
						return 1;
				}
				break;
	}
	return 0;
}

void give_reward_necropolis(object *ob,object reward_giver) {
	int ref_pot;
	int ref_exp;
        int ref_tih;
	int gold = 100;
	int score = 500;
        int exp,pot,tih;
	object *team,member;
	string reward_msg,mazedir;
	
	if(!ob || sizeof(ob)==0 )
			return;
	team = ob;
	//mazedir = MAZE_D->query_maze_dir(reward_giver);
	//foreach(member in team) {
			//if(!member)
			//	continue;
			//if(!environment(member) || !environment(member)->query("virtual_room"))
				//continue;
			//if(mazedir!=MAZE_D->query_maze_dir(member))//����ͬһ��������
			//	continue;
                        ref_pot = 300000;
                        ref_exp = 600000;
                        ref_tih = 50000;
                        /*
                        if(count_gt(member->query("combat_exp"),1000000000)) {
                                        ref_tih = 10000;
                                        ref_pot = 50000;
                                        ref_exp = 100000;
                        } else if (count_gt(member->query("combat_exp"),600000000)) {
                                        ref_tih = 20000;
                                        ref_pot = 100000;
                                        ref_exp = 200000;
			} else if (count_gt(member->query("combat_exp"),300000000)) {
                        */
                        if(member->query("combat_exp",1)<10000000) {
                                        ref_tih = 30000;
                                        ref_pot = 150000;
                                        ref_exp = 300000;
			}
			exp = ref_exp;
			pot = ref_pot;
                        tih = ref_tih;
			
			reward_msg =HIR"Ĺ԰��Σ��������㱻�����ˣ�\n\t\t" +
			chinese_number(exp) + "��ʵս����\n\t\t"+
			chinese_number(pot) + "��Ǳ��\n\t\t" +
                        chinese_number(tih) + "�����\n\t\t" +
			chinese_number(score) + "������\n\t\t" + 
			chinese_number(gold) + "���ƽ�\n"NOR;
			tell_object(member,reward_msg);
			member->add("combat_exp",exp);
			member->add("potential",pot);
                        member->add("experience",tih);
			member->add("score",score);
                        member->add("balance",gold*10000);
			member->set_temp("maze/time",time());
	}

/*
void die() {
	object mazeobj,item,ob,killer,corpse;
	string dir,userid,quest;
	int quest_index;
	object owner;
	//if(!mazeobj=get_mazeobj())
	//		return;
	//::die();
	killer = query_temp("last_damage_from");
	if(!killer)
		{
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        destruct(this_object());
			return;
		}
	mazeobj=killer;
	quest_index = mazeobj->query("quest/quest_index");
	if(quest_index == 7) {
			give_reward_necropolis(query_players(),this_object());
			dir = base_name(mazeobj);


					if (! sizeof(killer->query_team_member()))
					        owner = killer;
					else
					{ 
					        if (killer->is_team_leader())
					                owner = killer;
					        else
					                owner = killer->query_team_leader();
			                }
                                        
					ob = new(__DIR__"obj/taoist_tape");
					ob->move(environment());
					ob->play_sound_8(dir,0); 
                        for (int i = 0; i < 10; i++) 
                        {
                                item = new("/p/newweapon/weaponobj/material1" + random(2));
    		                item->move(environment());
                                item = new("/p/newweapon/weaponobj/kuangshi1" + (3 + random(3))); 
                                item->move(environment()); 
                        }  		

                        if (random(100) < 2)
                        {
                                item = new("/p/newweapon/weaponobj/kuangshi2");
                                item->move(environment());
                        }
                        if (random(100) < 5)
                        {
                                item = new("/p/newweapon/weaponobj/material7");
                                item->move(environment());
                        }
                        if (random(100) < 9)
                        {
                                item = new("/p/newweapon/weaponobj/buliao1.c");
                                item->move(environment());
                        }


        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        destruct(ob);
        destruct(this_object());
        return;
			}

			//reset_eval_cost();
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        destruct(this_object());
return;
	
//	destruct(ob);
}

*/
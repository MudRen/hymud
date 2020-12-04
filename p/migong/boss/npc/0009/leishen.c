#include <ansi.h>

inherit BOSS;

int showpower1();
int showpower2();
int combatpower();
int powerup();

void create()
{
	set_name("����", ({ "lei shen", "leishen", "lei" }) );
	set("title", HIY"���� "HIG"�巽�������"NOR );
	set("long", "�巽����������ȥ����ܳ������г�һ��������\n");
	set("nickname",HIR"̫����"NOR);
	set("name_color", "HIC");
	set("gender", "����");
	set("age", 22);
        
	set("str", 248);
	set("con", 252);
	set("dex", 222);


          set("combat_exp", 70000000);
        set("level", 70);
	set("max_qi", 2050000);
	set("max_jing", 2050000);
        set("jing", 2200000);
        set("max_jing", 2200000);
	set("jiali",1000);
	set("max_neili",900000);
	set("neili",900000);
	set("attitude", "aggressive");

        set("chat_chance", 5);
        set("chat_msg", ({
        	(: showpower1 :) ,
        	(: showpower2 :)
        }) );    


	set("combat_exp", 72000000+random(2000000));

set_skill("force",880);
	set_skill("strike",880);
	set_skill("literate",880);	
	set_skill("cuff",880);	
	set_skill("changquan",880);
        set_skill("luohua-jian",880);
        set_skill("sword",880);
set_skill("ill-quan",880);
set_skill("luoriquan",880);
set_skill("qinnashou",880);
	set_skill("array",800);
	set_skill("taoism", 800);
set_skill("shizi-zhan",880);
set_skill("dahong-quan",880);
set_skill("qishang-cuff",880);
set_skill("kongling-jian",880);
set_skill("luofeng",880);
set_skill("taiyi",880);
set_skill("sanqing-jian",880);
set_skill("kongdong-xinfa",880);

        //set_skill("doomsword",880);
        //set_skill("chilian-shenzhang",880);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",880);

        map_skill("unarmed","qishang-cuff");
        map_skill("sword","sanqing-jian");
        map_skill("force","kongdong-xinfa");
        map_skill("dodge","luofeng");
        map_skill("parry","qishang-cuff");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
		(: combatpower :),
					(: combatpower :),
								(: combatpower :),
                (: perform_action, "sword.huan" :),
                (: perform_action, "sword.jianmang" :),
                (: perform_action, "sword.sanlianji" :),	
                (: perform_action, "sword.wanxiang" :),	
    (: perform_action, "dodge.bagua" :),	                	
                (: perform_action, "parry.hunpofeiyang" :),
                (: perform_action, "parry.qishang" :),
            (: exert_function, "zhenhuo" :),
            (: exert_function, "dingshen" :),
            (: exert_function, "sanqing" :),
            (: exert_function, "wuxing" :),			
		(: command("unwield changjian") :),
		(: command("wield changjian") :),

        }) );
        

        set_temp("apply/attack", 500);
        set_temp("apply/damage", 3600);
        set_temp("apply/armor", 3600);
        set_temp("apply/defence",500);
        
        // ��Ʒ����
	        set("bonus", random(100000)+5000);
set("killer_reward", ([
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&50"   :   5000,
                "GE&4"   :  5000,
                "JD&5"   :  5000,
                "YC&3"   :  5000,
                "WG&3"   :  5000,
               "KS&6"   :   500,
                "BL&6"   :  500,
                "YW&5"   :  500,
                "YA&5"   :  500,
                "TW&480"   :  1000,
                "TA&480"   :  1000,
"TZ&0"   :  550,
	]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/money/gold")->set_amount(500);
  	//carry_object(WEAPON_DIR"hammer/leigonghong");

	// init_npc(this_object(), 3, 13, 0, 100);
// �Զ�����NPC���Ժͼ��ܣ���һ���������롣
// ��һ������ΪNPC��OB
// �ڶ�������ΪNPC�����ɣ�1����2�ظ�3����4�¹�5ѩɽ6��ׯ7����8�޵׶�����Ϊ������������Ϊ�������
// ����������ΪNPC�ļ��ܣ���NPC�ĵȼ�����(1:50)��ȱʡ��0Ϊ������
// ���ĸ�����ΪNPC�����Ժ�״̬�ȼ�����NPC�ĵȼ����ã�ȱʡ��0Ϊ������
// ���������ΪNPC��ǿ�ȣ�ȱʡΪ100
}

void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;
        
        if( !me->is_character() || me==this_object() || !me) return;
        if(me->query("vendetta/authority")) return;
        if(!userp(me)) return;
        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

int combatpower()
{
	if (this_object()->is_busy()) this_object()->start_busy(1);
	message_vision( HIY"\nһ����ɫ�Ļ���ȼ��������$N˫��һָ������������������\n" NOR,this_object());
	remove_call_out("powerup");
	call_out("powerup",random(10)+2);
	return 1;
}


int showpower1()
{
	tell_object(environment(this_object()),HIY"\n\n\t��������һ��������\n\n\n"NOR);
	return 1;
}
int showpower2()
{
	tell_object(environment(this_object()),HIY"\n\n\t��������һ��������\n\n\n"NOR);
	return 1;
}



int powerup()
{
	int dam, i , num;
	object *inv;
	message_vision( HIY"\nһ�����������㣡����\n",this_object());
        inv = all_inventory(environment(this_object()));
        num = sizeof(inv);
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        dam = 26000 / num;
        for(i=sizeof(inv)-1; i>=0; i--)
        {
        	if( living(inv[i]) && inv[i] != this_object() )
        	{
//        		dam = dam - inv[i]->query_combat_level("DF_spells");
        		if(dam <0) dam = 0;
        		inv[i]->start_busy(2);
        		inv[i]->receive_wound("qi", dam, this_object());
        		inv[i]->receive_wound("jing", dam/2, this_object());
        		COMBAT_D->report_status(inv[i],1);
        	}
        }
        return 1;
}


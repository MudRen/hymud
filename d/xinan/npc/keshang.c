// keshang.c
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
                          
string *first_name = ({
    "��", "��", "��", "��", "��", "��", "��", "��", 
                    });

string *last_name = ({
    "��", "��", "��" ,"��", "��", "��", "��", "��",
                    });                                              


void create()
{
    string name;
    name = first_name[random(sizeof(first_name))];
    name += last_name[random(sizeof(last_name))];
	set_name( name , ({ "ke shang", "trader", "shang" }));
    set("title", "��·����" );
    set("gender", "����" );
	set("age", 15+random(50));
	set("qi",400);
	set("max_kee",400);
	set("eff_kee",400);
	set("jing",400);
	set("max_sen",400);
	set("eff_sen",400);
	
	set("long",
		"����һ�������ڸ������֮��Ŀ��̣���ߴ��˲��ٻ��\n");
	set("chat_chance", 10);
        set("chat_msg", ({
(: random_move :),
"����˵����˵ǰ����ǿ����Ҳ��֪�ǲ������.....\n",
"����վ��·��Ъ�˿�����\n",
 }));
	set("combat_exp", 100000+random(400000));
    set("social_exp", 100000+random(400000));
	set("vendor_goods", ({
		"/d/village/npc/obj/stick",
		"/d/village/npc/obj/shoes",
		"/d/village/npc/obj/bottle",
		"/d/village/npc/obj/egg",
		"/d/huanghe/npc/obj/tieqiao",
		"/d/xingxiu/npc/obj/yangrou",
		"/d/lanzhouchen/npc/obj/paomo",
		"/d/city/npc/obj/jiudai",
		"/d/lanzhou/npc/obj/jiouhulu",
		"/d/lanzhou/npc/obj/maoniurou",
	}));
	set("attitude", "friendly");
	setup();
   	carry_object( "/clone/misc/cloth")->wear();
/*
	carry_object( goods[random(sizeof(goods))]);
	carry_object( goods[random(sizeof(goods))]);
	carry_object( goods[random(sizeof(goods))]);
*/
	set("possitive_score",100-random(400));
}

int refuse_killing( object who )
{
	object *inv;
	int i;
	message_vision("���̴�е���������������ѽ�� ��������������\n", who);
	inv = all_inventory( environment(this_object()) );
	for ( i = 0; i < sizeof(inv); i++ )
	{
		if( inv[i]->query("id") == "ke shang" )
		inv[i]->kill_ob(who);
	}
	return 0;
} 


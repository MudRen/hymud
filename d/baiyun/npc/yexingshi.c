 inherit NPC;
#include <ansi.h> 
inherit F_VENDOR; 
void create()
{
        set_name("Ҷ��ʿ", ({ "ye xingshi", "ye"}) );
        set("nickname", CYN "ҽ��"NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
        set("age", 44);
        set("per", 25);
        set("int",28);
        set("attitude","friendly");
        set("class","shaolin");

        set("max_neili", 1000);
        set("force", 1000);
        set("force_factor",50); 
        set("long",
        "Ҷ��ʿ���������ȴ�˧��Ψ���׼ҵ��ӣ�Ҳ�ǽ����о���ʢ�����Ĵ���ҽ֮����\nҽ�����������¹��ϣ�����Ϊ��ҽ�ɡ���\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
        name()+"���۳���̾�����޹�Ҷ�³��ڴ˳��ӣ���ȷ�Ǹ��ɾ�������ڡ�\n",
        "Ҷ��ʿ�������ο�Ц����Ҷ������ΰ��ҡ��롱�����Ƴǣ���֪����Ϊ�Σ�\n",
        "Ҷ��ʿ���˷����С��Ƶ��ھ�������ü����Ҷ����ü��΢����ڣ��ѵ����˶���\n",
        }) );
        
    set("combat_exp", 800000);
        
        set_skill("move", 500);
        set_skill("dodge", 500);
        set_skill("force", 160);
        set_skill("unarmed",200);

        set_skill("changquan",200);
        set_skill("parry",200);
        
    map_skill("unarmed", "changquan");

	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/clone/misc/yaodan",
                "/clone/misc/neilidan",
		"/d/shenlong/obj/xionghuang",
	}));      
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}      
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}     

inherit NPC;

void create()
{
        set_name("�첨��Ц", ({"tianboer xiao", "xiao"}));
        set("long", "������ʯɽ�̲�̶��С����\n");
        set("age", 30);
	set("title", "������");
        set("attitude", "friendly");
        set("gender", "����");
	set("class", "dragon");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",1200);
        set("max_jing", 1000);
        set("combat_exp", 400000);
  set("combat_exp", 500000);

        set("neili", 1200);
        set("max_neili", 1200);
        set("neili",400);
        set("max_neili", 700);
        set("force_factor", 40);
        set("mana_factor", 20);
        set_skill("unarmed", 120);
        set_skill("force", 120);
        set_skill("spells", 120);
        set_skill("dodge", 120);
	set_skill("whip", 120);
	set_skill("hellfire-whip", 100);
	set_skill("parry", 120);
	map_skill("whip", "hellfire-whip");
	map_skill("parry", "hellfire-whip");
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/whip/tielian")->wield();
}
void relay_emote(object ob,string verb)
{
	if( ob->query("name")!="Ц������" ) return;
        switch(verb) {
        case "kick":
                        command("say �����ַ�����...\n");
                break;
        case "wake":
                        command("wake");
		break;
        case "poke":  
                        command("poke xiao");                                        
                break;
        case "consider":  
                        command("poor tian");                                        
                break;
        case "grin":  
                        command("hehe tian");                                        
                break;
	case "lazy":
			command("lazy xiao");
		break;
        }
}

�
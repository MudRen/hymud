#include <ansi.h>
inherit NPC;
mapping *data=({
(["name":"����",	"id":"xizang man",	"mw":1,	]),
(["name":"����",	"id":"xizang man",	"mw":1,	]),
(["name":"�¼�÷��",	"id":"xizang man",	"mw":1,	]),
(["name":"г������",	"id":"xizang man",	"mw":1,	]),
(["name":"����",	"id":"xizang man",	"mw":1,	]),
(["name":"÷��",	"id":"xizang man",	"mw":1,	]),				
(["name":"�������",	"id":"xizang man",	"mw":1,	]),				
(["name":"׿��",	"id":"xizang man",	"mw":1,	]),				
(["name":"��ķ",	"id":"xizang man",	"mw":1,	]),					
(["name":"��������",	"id":"xizang man",	"mw":-1,	]),					
(["name":"������Ħ",	"id":"xizang man",	"mw":-1,	]),					
(["name":"���ͼ���",	"id":"xizang man",	"mw":-1,	]),					
(["name":"ȥ������",	"id":"xizang man",	"mw":-1,	]),					
(["name":"�������",	"id":"xizang man",	"mw":-1,	]),					
(["name":"��������",	"id":"xizang man",	"mw":-1,	]),										
(["name":"��������",	"id":"xizang man",	"mw":-1,	]),					
(["name":"��ɣ����",	"id":"xizang man",	"mw":-1,	]),					
(["name":"����",	"id":"xizang man",	"mw":-1,	]),					
(["name":"���",	"id":"xizang man",	"mw":-1,	]),					
(["name":"����",	"id":"xizang man",	"mw":-1,	]),					
(["name":"�༪",	"id":"xizang man",	"mw":-1,	]),										
(["name":"����",	"id":"xizang man",	"mw":-1,	]),					
(["name":"Ⱥ��",	"id":"xizang man",	"mw":-1,	]),					
(["name":"����",	"id":"xizang man",	"mw":-1,	]),					
(["name":"�ʸ�",	"id":"xizang man",	"mw":-1,	]),					
(["name":"����",	"id":"xizang man",	"mw":-1,	]),					
(["name":"�μ�",	"id":"xizang man",	"mw":-1,	]),										
(["name":"����",	"id":"xizang man",	"mw":-1,	]),										
(["name":"�ղ�",	"id":"xizang man",	"mw":-1,	]),										
(["name":"����",	"id":"xizang man",	"mw":-1,	]),										
(["name":"��ķ",	"id":"xizang man",	"mw":-1,	]),													
(["name":"����",	"id":"xizang man",	"mw":-1,	]),										
(["name":"��ɭ",	"id":"xizang man",	"mw":-1,	]),											
(["name":"�װ�",	"id":"xizang man",	"mw":-1,	]),											
(["name":"��ɣ��ȴ",	"id":"xizang man",	"mw":-1,	]),											
(["name":"��������",	"id":"xizang man",	"mw":-1,	]),													
(["name":"���͹���",	"id":"xizang man",	"mw":-1,	]),											
(["name":"�༪Ͻ��",	"id":"xizang man",	"mw":-1,	]),											
(["name":"��ɣ����",	"id":"xizang man",	"mw":-1,	]),													
(["name":"���յ���",	"id":"xizang man",	"mw":-1,	]),											
(["name":"�ε��ѹ�",	"id":"xizang man",	"mw":-1,	]),											
(["name":"���մε�",	"id":"xizang man",	"mw":-1,	]),													
(["name":"����ǿ��",	"id":"xizang man",	"mw":-1,	]),											
(["name":"��ķ����ɣ",	"id":"xizang man",	"mw":-1,	]),													
(["name":"����",	"id":"xizang man",	"mw":-1,	]),											
(["name":"��׿",	"id":"xizang man",	"mw":-1,	]),											
(["name":"����",	"id":"xizang man",	"mw":-1,	]),													
(["name":"��ܽ���",	"id":"xizang man",	"mw":-1,	]),											
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",300000);
	if( weapon)	set_skill("blade",20);
	set_skill("unarmed",20);

        set("dex",200);

	set_skill("blade",120);
	set_skill("sword",120);
	set_skill("club",120);
	set_skill("whip",120);
	set_skill("throwing",120);
	set_skill("parry",120);

set("per",16+random(20));
	set_skill("dodge",300);
	set("shen_type",npc["mw"]);
set("gender", "����");
if (npc["mw"]==1) set("gender", "Ů��");
else set("gender", "����");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :),
        }) );
	set("max_neili",500+random(8550));
	set("max_jing",500+random(8550));
		set("max_qi",500+random(8550));
	set_skill("unarmed",230);
	set_skill("parry",230);
	set_skill("dodge",230);
	set("age",20+random(30));
	set("combat_exp",55000+random(8555000));
	set_temp("apply/attack",120);
	set_temp("apply/defense",20);
	set_temp("apply/armor",120);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
           (: random_move :),
           (: random_move :),
           (: random_move :),
        }) );

        set_temp("apply/attack", 30+random(380));
        set_temp("apply/defense",30+random(380));
        set_temp("apply/armor", 30+random(380));
        set_temp("apply/damage", 30+random(380));
        setup();
        set("check_time", time());
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("silver",1+random(10));
}
       

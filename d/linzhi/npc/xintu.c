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

	set_name(npc["name"],({ "xintu" }));
//        set_name("ȥ������", ({ "xintu"}) );
        set("gender", "����" );
        set("age", 55);
        set("str", 10);
        set("long", @LONG
һ��װ���������Ѻ��ƾɵĲ��ˣ�������������ͽ��
LONG
);
        set("attitude", "peaceful");
        set("title", "��ʥ��ͽ");
        set("combat_exp", 10000);
        set_skill("unarmed", 70);
set("gender", "����");
if (npc["mw"]==1) set("gender", "Ů��");
else set("gender", "����");
        set_skill("force", 50);

    set_skill("iron-cloth", random(50)+100);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
 "\n"+query("name")+"������������һ�ݣ��岽һߵ��ִ�Ŷ���ʥ����ǰ�����š�\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/hada")->wear();
 
}  

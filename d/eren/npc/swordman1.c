#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("title","��������");
        set("long", "һ�����ҵĵ��ˣ���������ͨ��ǣ�˫üб�����ޡ�\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4300000);
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1500);
        set("neili",1500);
        set("force_factor",50); 
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30); 
        set("reward_npc", 1);
        set("difficulty", 5); 
        set("inquiry", ([
                "������" : "������ǵ�һ���Ҵ�����˹ȵ��������ˡ�\n",
                "���˹�" : "ʮ�����ɢ��ɢ�������������˹�����̫ƽ���ˡ�\n",
        ]));
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "������̾�������������Ե��������书֮ǿǿ�����£�ƶ���������ţ�
������һ������������������\n",
                
        }) );

        set_name("������",({"zang yizi"}));
        set("force_factor",50);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        
}

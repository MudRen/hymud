#include <ansi.h>
#include <command.h>
inherit NPC; 
void create()
{
        set_name("Ǭ����ħ", ({ "evil" }) );
        set("title",HIR"ʮ����ħ֮"NOR);
        set("title",HIR"ʮ����ħ֮"NOR);
        set("age", 400);
        set("long", "����ʮ�ص���ħ����ʽ��������ħ�������еİ��˰��ޣ��еķ��˷��ޣ��е���״
���ˣ�ȴ�����ˣ��е���״���ޣ�ȴƫƫ��һ�����ġ����У����У��һ��У�����
�У�û��һ���ط���������Щ��ħ����\n");
        set("attitude", "aggressive");
        set("combat_exp", 9000000);
        
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",130); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        set("statue",0);

   setup();
        carry_object(__DIR__"obj/msword")->wield();
}    
void die(){
        object me,owner,ob;
        
        ob=this_object();
        
        message_vision(HIR"\nһ�ɺ�������$N����һ��ʯ��,һ�������ˡ�\n"NOR, this_object());
        ob->start_busy(10);
        ob->set("statue",1);
        call_out("reborn",20);
        "/cmds/imm/full"->main(this_object(),"");
        ob->set("resistance/kee",100);
        ob->set("resistance/gin",100);
        ob->set("resistance/sen",100);
        ob->remove_all_killer();
        
} 
int reborn(){
        object ob;
        
        ob=this_object();
        message_vision(HIR"һת�۵Ĺ���,�������ۣ�ʯ�������ֻ������\n"NOR,ob);
        ob->set("resistance/kee",30);
        ob->set("resistance/gin",30);
        ob->set("resistance/sen",30);
        ob->set("statue",0);
        ob->stop_busy();
        ob->move(environment(ob));
        return 1;
} 
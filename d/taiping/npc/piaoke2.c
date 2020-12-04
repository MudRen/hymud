 inherit NPC;
void create()
{
        set_name("上官磷", ({ "piaoke", "ke"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这位干干瘦瘦的嫖客，是“斧头帮“的帮主上官磷。\n");
        
        set("combat_exp", 4000000);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        
        }) );
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
        
        ]) );           

        
        setup();
        carry_object(__DIR__"obj/axe")->wield();
        
} 
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        message_vision("上官磷伸了个懒腰：“大爷快活去了。”说罢又上了床。\n",this_object());
        destruct(this_object());
}    

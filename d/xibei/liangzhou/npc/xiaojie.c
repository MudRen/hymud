// Npc : xiaojie.c  С��
// hydra

#include <ansi.h>
inherit NPC;

int ask_me( object );

void create()
{
    set_name( "С��", ({ "xiao jie", "xiaojie" }) );
    set( "title","�Ÿ�" );
    set( "attribute", "friendly" );
    set( "gender", "Ů��" );
    set( "age", 18 );
    set( "long", @LONG
�ż�С�������黭������ͨ���ټ��ϳ��Ĺ�ɫ���㣬�����ݳ���ǳ�������
LONG
    );
    
    set( "per",35 );
    set( "int",34 );
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
    
    set( "inquiry",([
        "���"      :   (: ask_me :),
        "���"      :   (: ask_me :),
    ]) );
        
    setup();
    carry_object( "/clone/misc/cloth" )->wear();

}

int ask_me( object ppl )
{
    object env,*ob;
    int i,time,flag=0;
    ppl = this_player();

    
    env = environment(ppl);
    if ( env->query("short") != "��¥" )
    {
        tell_object(ppl,CYN"С�����������黹�ǵ��һ��˸�¥��˵�ɡ�"
            "�����˶����ӣ�����©�˷�����\n"NOR);
         return 0;
    }
    


    

        tell_object(ppl,CYN"С�����˸��񣬵�����һ�����̴�ʦ�ˡ�\n"
            "˵�գ�����ӯӯ��¥��ȥ��"NOR);
        ppl->set_temp("����/can_lie",1);
        call_out("hide_me",1);
        return 1;
 
}

void hide_me()
{
    destruct( this_object() );
}

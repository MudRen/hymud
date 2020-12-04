//  ��׼��ؤ    /clone/npc/beggar.c
//  By lin
//  Hydra copied from lanzhou

#include <ansi.h>
inherit NPC;
int ask_me( object );
string talk_me( object );

void create()
{
    set_name( "��ؤ", ({ "qi gai", "qigai", "beggar" }) );
    set( "gender", "����" );
    set( "combat_exp", 100 );
    set( "per", 14 );
    set( "force", 200 );
    set( "max_force", 200 );
    set( "chat_chance", 15 );
    set( "chat_msg", ({
        "��ؤ˵���������ĵĴ�ү�ġ�����Ҫ���ļ���Ǯ�ɡ���\n",
        "��ؤ������ش��˸���Ƿ��\n",
        "��ؤ����׽ס�����ϵ�ʭ�ӣ����������������û�����⣬ȫ�����Ǹ�ҧ���ˡ���\n",
    }) );
    set("inquiry",([
        "��æ"      :   (:ask_me:),
    ]) );
    
    set("talk_limit",([
        "hydra/can_talk_qigai"      :       1,
        "hydra/shaolin/pending_kaoyan" :    1,
    ]) );
    set("talk_msg",({
        (: talk_me :),
    }) );
    
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}

int accept_object( object ppl, object obj ) //���˶���˵�û���
{
    command( "smile" );
    command( "say ����л��λ" + RANK_D->query_respect( ppl ) +
        "��������һ�����кñ��ģ���" );
    return 1;
}

int accept_fight( object ppl )              //��������ս��
{
    command( "say ��" + RANK_D->query_respect( ppl ) +
        "������С����͹�������\n");
    (: random_move :);
    return 0;
}

void init()
{
    object ppl = this_player();

    ::init();
}

string talk_me( object ppl )
{
    string msg;
    ppl = this_player();
    if ( ppl->query_temp("����/meet_qigai") ) 
    {
        tell_object(ppl,CYN"��ؤ������ʲô���Ѵ�ʦ�ٹ�����\n"NOR);
        return "";
    }
    msg = CYN"��ؤ���������������һ�ۣ����ĸ���˵����λ��ʦ����������\n";
    msg +=   "���Ϸ���˵�������ڰ���Ա�⽵�����ˣ�����ؤ��ǳ����壬��\n";
    msg +=   "����ҪС�ģ��Ƕ��˱Ƚ�������˵���������ϴ�����ؤ��������\n";
    msg +=   "�ڹ��������¡�\n";
    msg +=   "���������ؤ�����ݷֶ����Ϣ���Ƕ���������������Ͽ��ܻ�\n";
    msg +=   "���ż�С�����֡������ʦ��ʲô���ѿ��������ǰ�æ��\n"NOR;
    ppl -> set_temp("����/meet_qigai",1);
    tell_object ( ppl,msg );
    return "";
}

int ask_me( object ppl )
{
    string msg;
    ppl = this_player();
    if ( !ppl->query_temp("����/meet_qigai") )
    {
        return 0;
    }
    if ( ppl->query_temp("����/ask_qigai") )
    {
        tell_object(ppl,CYN"��ؤ������ʦһ��С�ģ�\n"NOR);
        return 1;
    }
    msg = CYN"��ؤ������ʦ��Ȼ�����ˣ�����һ������֪�Ƿ���У���ʦ��װ\n";
    msg +=   "���ż�С�㣬��С���Ҹ��ط�������������ϲ�Ҫ˯�ڹ뷿�\n";
    msg +=   "Ȼ���ʦ����������С��Ĵ��ϣ����ǲɻ�����ǰ������֮ʱ��\n";
    msg +=   "��ʦ�ɹ��������ֲ�����\n";
    msg +=   "����С�ı��ݾ��ߣ�������ԵĻ�����ؤ�������ʦһ��֮����\n"NOR;
    tell_object( ppl,msg );
    ppl->set_temp("����/ask_qigai",1);
    return 1;
}


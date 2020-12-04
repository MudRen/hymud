// ���� /d/city/chuzhou/npc/chake.c
// by lala, 1997-12-14

inherit NPC;

string *name = ({
"������", "Ǯ����", "������", 
     });
void create()
{
    set_name( name[random(sizeof(name))], ({ "cha ke", "chake", }) );
    set( "gender", "����" );
    set( "age", 45 );
    set( "long", @LONG
���Ǳ��ǵ�һλ�оӵ�������ǰ����ЩС�٣����ڼ����£�ÿ�����ݲ�ݡ���
����Щ�˵���Ϣ������ͨ��
LONG
    );
    set("combat_exp", 5000);
    set("social_exp", 15000);
    set("positive_score", 500);
    set("negative_score", 100);
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);

    setup();
          
    carry_object( "/clone/misc/cloth")->wear();
    add_money( "coin", 100 + random(50) );
}          

void init()
{
   object me = this_player();
   object ob = this_object();
   int relative;

   if ( userp( me )
     && relative = me->query_marks( "marks/chuzhou/" + ob->query("name") ) 
        > 0 )
        call_out( "greeting", 2, me, ob, relative );
}

void greeting( object me, object ob, int relative )
{
    string str;

    switch( random( relative/10 ) )
    {
        case 0:
            str = "$Nһתͷ������$n�߽��������ͷ�����Ǵ��к��ˡ�\n";
            break;
        case 1:
            str = "$N����ͷ�Ȳ裬һ̧ͷ������$nվ������ǰ��Ц��һЦ��\n";
            break;
        case 2:
            str = "$nһ�߽��������Ϳ���$N���ڶ��Լ����к������þò�������\n";
            break;
        case 3:
            str = "$N����$n�߽�������æվ����˵����������꣬�һ��һᣡ��\n";
            break;
        case 4:
            str = "$Nһ����$n������ǰ���񣺡���ѽ����ô�������п���������\n";
            break;
        default:
            str = "$Nһ��ץס$n�����ӣ�������˵����ѽ������ʲô����㴵����������\n";         
            break;
    }
    message_vision( str, ob, me );
}

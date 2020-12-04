/* driftsand.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980421
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980421
 * ����ĺ�����Ҫ�����ɳ�Ĺ���*
 */


//����ɳ���³�����Ϣ��
string * fall_msg = ({
    HIY"��ֻ�������������³���������\n"NOR,
    HIY"���˫���Ѿ������ı�ɳ����ס�ˡ���\n"NOR,
    HIY"ɳ���Ѿ��ǵ��������������\n"NOR,
    HIY"��Խ��Խ�£�����ز����¶�������ɳ�ӣ���е�����Խ��Խ�����ˡ�\n"NOR,
    HIY"ɳ����ȫ��ס����ĿڱǺ��ۡ���\n"RED"����ǰһ�ڡ�����\n"NOR,
});

//������ɳ����init�ﴥ��
void eventFall( object me )
{
    if (!me) return;
    if( random( me->query( "kar" ) ) > 20 )
        return;
    if( environment(me) != this_object() ) return;
    if( me->query_temp("hydra/desert/in_drift") ) return;
    message_vision( "$NͻȻ��������ɳ�С�\n",me );
    me->disable_command( "verb","��������ɳ֮�У����ǲ�Ҫ�����ĺá�" );
    //me->set( "no_get",1 );
    //me->set( "no_get_from",1 );
    me->set_temp( "hydra/desert/in_drift",1 );
    call_out( "check_depth",5,me );
}

//����ɳ��Խ��Խ��Ĺ��̡�����
void add_depth( object me )
{
    int depth;
    if (!me) return;
    depth = me ->query_temp( "hydra/desert/depth" );
    
    if ( ! me->query_temp( "hydra/desert/in_drift" ) ) return;
    tell_object( me,fall_msg[depth] );
    me ->add_temp( "hydra/desert/depth",1 );
    if ( depth >= 4 )
    {
        me -> delete_temp( "hydra/desert/depth" );
        me -> delete_temp( "hydra/desert/in_drift" );
        me -> enable_path();
        me -> die();

    }

}

// ������Ƿ���ȫ����ɳ��û��
// ���depthΪ5��������
void check_depth( object me )
{
if (!me) return;
    add_depth( me );
    if (me)
{
    if( (int)me->query_temp( "hydra/desert/in_drift" ) )
        call_out( "check_depth",5,me );
}
}

// ����ɳ�������Ķ���
// jump: ������ɳ�����˵�dodge�й�
// drop: �������ϵĸ��ء�
int do_jump( string arg )
{
    object me;
    int my_dodge_dengji,my_encum;
    me = this_player();
    my_dodge_dengji = me -> query_xiuwei_dengji( "dodge" );
    my_encum = me->query_encumbrance()*100/me->query_max_encumbrance();

    if ( arg ) return 0;
    if ( !me->query_temp( "hydra/desert/in_drift" ) ) return 0;
    if( my_encum <= my_dodge_dengji*10 )
    {
        message_vision( "$Nһ�����ɳ�������˳������������� \n",me );
        me ->enable_path();
        me ->delete_temp( "hydra/desert/in_drift" );
        me ->delete_temp( "hydra/desert/depth" );
        write( CYN"�ò����������������������ڻ�����δ������\n"NOR );
        me -> start_busy( 3 );
    }
    else
    {
        message_vision( "$Nһ������������ɳ��ȴ������������һЩ��\n",me );
        add_depth( me );
    }
    return 1;
}

int do_drop(object me, object obj)
{
        mixed no_drop;

        if( no_drop = obj->query("no_drop") )
                return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");

        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
                else
                {
                        message_vision( sprintf("$N����һ%s$n��\n",     obj->query("unit")),
                                me, obj );
                        write(HIY"ֻ���㶪�µĶ�����˲����ʧ����ɳ�У�\n"NOR);
                        destruct(obj);
                }
                return 1;
        }
        return 0;
}

int ActionDrop( string arg )
{
        object obj, *inv, obj2;
        object me = this_player();
        int i, amount;
        string item;

        if(!arg) return notify_fail("��Ҫ����ʲ�ᶫ����\n");

        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("������û������������\n");
                if( stringp(obj->query("no_drop")) )
                        return notify_fail( (string)obj->query("no_drop") );
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("��û��������" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() )
                        return do_drop(me, obj);
                else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        return do_drop(me, obj2);
                }
        }

        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        do_drop(me, inv[i]);
                }
                write("Ok.\n");
                return 1;
        }

        if(!objectp(obj = present(arg, me)))
                return notify_fail("������û������������\n");
        return do_drop(me, obj);
}


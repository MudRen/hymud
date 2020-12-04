// storyd.c

#include <ansi.h>

inherit F_DBASE;
string  zuji(string str);
private string *story_name = ({//ѡ�����
#if 1
        "new1",
        "new1",
        "new2",
        "new2",
        "new3",
        "new3",
        "new4",                
        "new4",                
        "new5",
        "new5",//10
        "new6",
        "new6",
        "new7",
        "new7",
        "new8",
        "new8",
        "new9",
        "new9",
        "new10",
        "new10",//20
        "new11",
        "new11",
        "new12",
        "new12",
        "new13",
        "new13",
        "new14",
        "new14",
        "new15",
        "new15",//30
        "new16",
        "new16",
        "laojun",
        "xiyou",
        "xiyou",
        "guanzhang",
        "nanji",
        "liandan",
	"caishen",
	"caishen",//40
	"zhengxi",
	"zhengxi",
	"zagang",
	"zagang",
	"songdai",
	"songdai",
	"niulang",
	"niulang",
	"pergive",
	"pergive",//50
	"kargive",
	"kargive",
	"neiligive",
	"neiligive",
#endif
        "normal",
});

private object  running_story;
private mapping history;
private int step;
int filter_listener(object ob);

void ready_to_start()
{
        remove_call_out("process_story");
        call_out("start_story", 2800);//���ʱ��
//        call_out("start_story", 3 + random(1));//���ʱ��
}
void go_on_process(object ob)
{
        remove_call_out("start_story");
        remove_call_out("process_story");
        call_out("process_story", 1, ob);
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "�¼�����");
        CHANNEL_D->do_channel( this_object(), "sys", "�¼�ϵͳ�Ѿ�������\n");

        history = allocate_mapping(sizeof(story_name));
        ready_to_start();
}

int clean_up()
{
        return 1;
}

object query_running_story()
{
        return running_story;
}

void start_story()
{
        string name;
        object ob;
        int i;

        ready_to_start();
        CHANNEL_D->do_channel( this_object(), "sys", "�¼�ϵͳ��ʼѡ���¼���\n");

        for (i = 0; i < 54; i++)
        {
                name = story_name[random(sizeof(story_name))];
                if (undefinedp(history[name]))
                        history += ([ name : 0 ]);

                if (time() - history[name] > 14400 || name == "normal")
                {
                        history[name] = (int)time();
                        break;
                }
        }

        if (i >= 54) return;

        CHANNEL_D->do_channel( this_object(), "sys", "�¼�ϵͳѡ�����¼�(" + name + ")��\n");

        name = STORY_DIR + name;
        if (ob = find_object(name))
                destruct(ob);

        catch(ob = load_object(name));
        running_story = ob;

        if (! objectp(ob))
                return;

        step = 0;
        go_on_process(ob);
}

void process_story(object ob)
{
        mixed line;
	object *listeners;
        string prompt;

        go_on_process(ob);

        if (! objectp(ob))
        {
                ready_to_start();
                return;
        }

        line = ob->query_story_message(step);
        step++;

        prompt = ob->prompt();
        if (! prompt) prompt = HIY "���������¡� " NOR;
        if (functionp(line)) catch(line = evaluate(line));
        if (stringp(line))
	{
		listeners = filter_array(users(), (: filter_listener :));
                message( "story",  prompt + WHT + line + "\n" NOR, listeners );
	}

        if (intp(line) && ! line)
        {
                ready_to_start();
                destruct(ob);
        }
}

int filter_listener(object ob)
{
	if (ob->query("env/no_story")) return 0;
	return 1;
}

void give_gift(string gift, int amount, string msg)
{
        int i;
        object ob;
        object env;
        object *players;
        string room;
string *dir2;

        players = users();
        if (sizeof(players) >= 5)
        {
                for (i = 0; i < 5; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                                
                        env = environment(ob);
                        while (env && env->is_character())
                                env = environment(env);
                        if (env) break;
                }
                if (i >= 5) return;

                if (objectp(env))
                        tell_room(env, msg);
                for (i = 0; i < amount; i++)
                {
                        ob = new(gift);
                        ob->move(env);
                        ob->set("no_get",0);
                        ob->set("no_give",0);
                        ob->set("no_drop",0);
                }
dir2=explode(base_name(env),"/");
room=zuji(dir2[1])+env->query("short");
CHANNEL_D->do_channel( this_object(), "rumor", "��˵:"+ob->name()+" ��"+room+"�������֡�\n");
                
	        CHANNEL_D->do_channel( this_object(),
			"sys", sprintf(NOR WHT "��Ʒ%s" NOR WHT "������"
				HIC "%s" NOR WHT "(%O" NOR WHT ")��\n" NOR,
                               ob->name(), env->query("short"), env));

        }
}


string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="����ɽ��";

if (str=="binghuodao")  

	output="���𵺵�";

if (str=="city")  

	output="���ݵ�";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="�����ǵ�";

if (str=="city4" || str=="changan")   

	output="�����ǵ�";

if (str=="dali")  

	output="�����";

if (str=="emei")  

	output="��üɽ��";

if (str=="foshan")  

	output="��ɽ��";

if (str=="gaibang")  

	output="ؤ���";

if (str=="gaochang")  

	output="�߲��Թ���";

if (str=="guanwai")  

	output="�����";

if (str=="guiyun")  

	output="����ׯ��";

if (str=="gumu")  

	output="��Ĺ�ɵ�";

if (str=="hangzhou")  

	output="���ݵ�";

if (str=="heimuya")  

	output="��ľ�µ�";

if (str=="hengshan")  

	output="��ɽ��";

if (str=="henshan")  

	output="��ɽ��";

if (str=="huanghe")  

	output="�ƺӾ�����";

if (str=="huashan")  

	output="��ɽ��";

if (str=="jinshe")  

	output="����ɽ����";

if (str=="lingjiu")  

	output="���չ���";

if (str=="lingzhou")  

	output="���ݵ�";

if (str=="meizhuang")  

	output="÷ׯ��";

if (str=="mingjiao")  

	output="���̵�";

if (str=="qingcheng")  

	output="���ɽ��";

if (str=="quanzhen")  

	output="ȫ���ɵ�";

if (str=="quanzhou")  

	output="Ȫ�ݵ�";

if (str=="shaolin")  

	output="�����µ�";

if (str=="shenlong")  

	output="��������";

if (str=="songshan")  

	output="��ɽ��";

if (str=="suzhou")  

	output="���ݵ�";

if (str=="taishan")  

	output="̩ɽ��";

if (str=="taohua")  

	output="�һ�����";

if (str=="tianlongsi")  

	output="�����µ�";

if (str=="wanjiegu")  

	output="��ٹȵ�";

if (str=="wudang")  

	output="�䵱ɽ��";

if (str=="xiakedao")  

	output="���͵���";

if (str=="xiangyang")  

	output="�����ǵ�";

if (str=="xiaoyao")  

	output="��ң�ֵ�";

if (str=="xingxiu")  

	output="���޺���";

if (str=="xueshan")  

	output="ѩɽ�µ�";

if (str=="xuedao")  

	output="��ѩɽ��";

if (str=="mr")  

	output="Ľ�����ҵ�";

if (str=="kunlun")  

	output="����ɽ��";

if (str=="tiezhang")  

	output="�����ŵ�";

if (str=="huizhu")  

	output="���岿���";

if (str=="yinju")  

	output="һ�ƴ�ʦ�ӵ�";

if (str=="menggu")  

	output="�ɹŲ�ԭ��";

if (str=="qianjin")  

	output="����ǧ��¥��";

if (str=="lingshedao")  

	output="���ߵ���";

if (str=="ruzhou")  

	output="���ݳǵ�";

if (str=="kunming")  

	output="������";

if (str=="jingzhou")  

	output="���ݵ�";

if (str=="yanjing")  

	output="�ྩ��";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="���ݵ�";

if (str=="jyguan")  

	output="�����Ա������ص�";

if (str=="changcheng")  

	output="�����Ա����ǵ�";

if (str=="fairyland")  

	output="���صĺ�÷ɽׯ";

if (str=="sdxl")  

	output="��ħ�������Ĺ";

if (str=="jqg")  

	output="�����";

if (str=="nio")  

	output="ţ�Ҵ��";

if (str=="feihu")  

	output="�������ص�";

if (str=="wuguan")  

	output="������ݵ�";

if (str=="village")  

	output="��ɽ���";

if (str=="taohuacun")  

	output="�һ����";

if (str=="pingan")  

	output="ƽ���ǵ�";

if (str=="lingxiao")  

	output="�����ǵ�";

if (str=="wudujiao")  

	output="�嶾�̵�";

if (str=="hj")  

	output="��ɽ����ԭ��";
if (str=="dali/yuxu")  

	output="��������۵�";
if (str=="dali/wuliang")  

	output="��������ɽ��";
if (str=="huanghe/yyd")  

	output="�ƺ�������";
if (str=="kaifeng")  

	output="����ǵ�";
if (str=="feitian")  

	output="������������";
if (str=="japan")  

	output="�ձ��񻧵�";
if (str=="tangmen")  

	output="���ŵ�";
if (str=="luoyang")  

	output="�����ǵ�";

if (str=="chengdu" || str=="city3")  

	output="�ɶ���";

if (str=="baihuagu")  

	output="�ٻ��ȵ�";

if (str=="heizhao")  

	output="�ٻ��ȡ����ӵ�";

if (str=="jiaxing")  

	output="���˵�";

if (str=="shiliang")  

	output="�¼�ׯ��";

if (str=="wuyi")  

	output="����ɽ����";

if (str=="yanping")  

	output="��ƽ�ǵ�";
	

if (str=="jiangling")  
{
	output="����ǵ�";
}

if (str=="yueyang")  
{
	output="�����ǵ�";	
}

if (str=="qilian")  
{
	output="����ɽ��";	
}

if (str=="shouxihu")  
{
	output="��������";	
}

if (str=="wuxi")  
{
	output="�����ǵ�";	
}

if (str=="yixing")  
{
	output="���˳ǵ�";	
}
if (str=="taiwan")  
{
	output="̨�������";	
}
if (str=="nanyang")  
{
	output="����������";	
}
if (str=="nanshaolin")  
{
	output="�����ֵ�����";	
}

if (str=="cangzhou")  
{
	output="���ݵ�����";	
}

if (str=="tanggu")  
{
	output="�����ǵ�����";	
}

if (str=="yunhe")  
{
	output="�������˺ӵ�";	
}

if (str=="hainan")  
{
	output="���ϵ���";	
}

if (str=="jindezheng")  
{
	output="�������";	
}

if (str=="yandang")  
{
	output="�㵴ɽ��";	
}

if (str=="jinling")  
{
	output="����ǵ�";	
}

if (str=="sandboy")  
{
	output="����ũ���";	
}

if (str=="huangshan")  
{
	output="��ɽ��";	
}

if (str=="yubifeng")  
{
	output="��ʷ��";	
}

if (str=="quanzhouchen")  
{
	output="Ȫ�ݳ��ڵ�";	
}

if (str=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="���� ����ɽ��";	
}

if (str=="annan")  
{
	output="���ϸ�����";	
}

if (str=="taiyuan")  
{
	output="̫ԭ������";	
}

if (str=="hefei")  
{
	output="�Ϸʸ�����";	
}

if (str=="jiujiang")  
{
	output="�Ž�������";	
}

if (str=="baling")  
{
	output="���긽����";	
}

if (str=="xinjiang")  
{
	output="�½�������";	
}
if (str=="dingxiang")  
{
	output="���帽����";	
}
if (str=="suiye")  
{
	output="��Ҷ������";	
}


if (str=="mayi")  
{
	output="���ر߽�������";	
}
if (str=="xuzhou")  
{
	output="���ݳǸ�����";	
}
if (str=="jinan")  
{
	output="���ϳǸ�����";	
}
if (str=="guizhou")  
{
	output="�����Ǹ�����";	
}

if (str=="nanchang")  
{
	output="�ϲ��Ǹ�����";	
}


if (str=="changsha")  
{
	output="��ɳ�Ǹ�����";	
}


if (str=="zhongzhou")  
{
	output="���ݳǸ�����";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="���ػ�ر�������";	
}

if (str=="tianshui")  
{
	output="��ˮ�Ǹ�����";	
}

if (str=="datong")  
{
	output="��ͬ��������";	
}
if (str=="ny")  
{
	output="��Զ�Ǹ�����";	
}
if (str=="fengtian")  
{
	output="ʢ���Ǹ�����";	
}

if (str=="yanmen")  
{
	output="���Źظ�����";	
}
if (str=="cloud")  
{
	output="����򸽽���";	
}
if (str=="xueting")  
{
	output="ѩͤ�򸽽���";	
}
if (!output)  
{
	output="δ֪�����";	
}

if (output=="")  
{
	output="δ֪�����";	
}


return output;
}

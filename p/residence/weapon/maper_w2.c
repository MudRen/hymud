// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;36m������Ԩ[2;37;0m", ({ "kunlun sword", "sword" }));
	set_weight(9827);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;36m	Ц�����˼�ʮ���Σ��ո�����ͷ��
	��ͭ���ﲴ���������죬�������ƣ� 
	����ʫ���ζϣ��Ϲ����� 
	�ѽ���Ȼ�����޴��й��ۡ� 
 
	��������·Զ����˭�����壬ŪӰ���ޣ�
	��Ӣ�۶�Ů�������Ž�
	�����ܵƻ����ʣ���꼻�һ�ֺ����ݣ�
	Ʈ��ߣ��������ƴ����� 
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m�Ƴɣ���ʮ�Ž�������Ǯ��[1;36m����֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;32m��������[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;34m����[2;37;0m [32mˮ[2;37;0m:[1;31m��˫[2;37;0m [1;35m��[2;37;0m:[1;34m����[2;37;0m 

���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m ��ʯ:[31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[31m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32mָ��[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "��ͼһ��");
		set("value", 25000);
		set("weapon_prop/intelligence",48);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",64);
		set("weapon_prop/percao",64);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",56);
    set("weapon_prop/dodge", 33);
    set("weapon_prop/parry", 64);
    set("weapon_prop/attack", 64);
    set("weapon_prop/armor", 48);
    set("weapon_prop/defense", 64);
    
    set("weapon_prop/neili", 64);
    set("weapon_prop/qi", 56);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 48);
    set("weapon_prop/damage", 63);

    set("wtypeA",8);
    set("wtypeB",6);
    set("wtypeC",12);
    set("wtypeD",7);
    set("wtypeE",6);
    set("wtypeF",8);
    set("wtypeG",6);
    set("wtypeH",6);
    set("wtypeI",7);
    set("wtypeJ",6);
    set("wtypeK",6);
    set("wtypeL",9);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 18);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(1953);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";
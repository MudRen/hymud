#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[37m΢��[2;37;0m", ({ "shentong armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;31m�����ͨ������Ҫƽ�ƣ���Ҫ���У����۹˼⣬���������ȣ�
������Ȼ����������࣬������ͣ�磬���绨��������ֶ���
[2;37;0m����һ���ɾ��Լ�Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ������������Ǯ��[1;31m��֮ͨ����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m ���������Լ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[35m��׼[2;37;0m [1;36m��[2;37;0m:[1;31m��˫[2;37;0m [36mľ[2;37;0m:[1;31m��˫[2;37;0m [32mˮ[2;37;0m:[1;31m����[2;37;0m [1;35m��[2;37;0m:[31m����[2;37;0m 
[1;34m��[2;37;0m:[1;31m��Ԫ[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ��Ԩ:[32m�ֲ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[1;36m����[2;37;0m ����:[35m��׼[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32m�ַ�[2;37;0m ���ļ��ɡ�

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
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",56);
		set("armor_prop/karey",56);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 72);
    set("armor_prop/parry", 56);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 595);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 56);
    set("armor_prop/qi", 56);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 356);

    set("wtypeA",6);
    set("wtypeB",12);
    set("wtypeC",14);
    set("wtypeD",6);
    set("wtypeE",6);
    set("wtypeF",6);
    set("wtypeG",6);
    set("wtypeH",13);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",12);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";
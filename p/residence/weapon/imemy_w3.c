// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

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
	set_name("[1;35mĞùÔ¯Ö®ÕÈ[2;37;0m", ({ "xuanyuan staff", "staff" }));
	set_weight(14721);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
[1;35mÎôÈÕ»ÆµÛ³Ö´ËÎïÁ¢ÓÚÖ¸ÄÏ³µÉÏ£¬ÇıÃÔÎí£¬É¨Òõö²£¬ÂÊÓ¦Áúºµ÷É£¬Óù°ÙÊŞ¶øÕ½ò¿ÓÈ£¡
[2;37;0mÕâÊÇÒ»¸ùÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®¾Å½ïËÄÁ½ËÄÇ®µÄ[1;35mĞùÔ¯Ö®ÕÈ[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31mÌìÏÂÎŞË«[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;33m½ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [33mÍÁ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;37mÀ×[2;37;0m:[1;35m¾øÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÌåÁé:[33mºÜ¸ß[2;37;0m ×ÏÊ¯:[35m±ê×¼[2;37;0m ÖÜÌì:[34mÏ¸Ëé[2;37;0m ³¤Éú:[31m¾«ÖÂ[2;37;0m ÍşÁ¦:[1;36mÍêÃÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¶ÉÄ½[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mµ¶·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "¶ÉÄ½");
		set("value", 25000);
		set("weapon_prop/intelligence",31);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 58);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 44);
    
    set("weapon_prop/neili", 28);
    set("weapon_prop/qi", 68);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 74);

    set("wtypeA",11);
    set("wtypeB",8);
    set("wtypeC",10);
    set("wtypeD",0);
    set("wtypeE",8);
    set("wtypeF",0);
    set("wtypeG",11);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",14);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_staff(1160);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";
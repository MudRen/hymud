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
	set_name("[1;36mÆßĞÇÁúÔ¨[2;37;0m", ({ "kunlun sword", "sword" }));
	set_weight(9827);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;36m	Ğ¦½­ºşÀË¼£Ê®ÄêÓÎ£¬¿Õ¸ºÉÙÄêÍ·¡£
	¶ÔÍ­ÍÓÏï²´£¬Ò÷ÇéÃìÃì£¬ĞÄÊÂÓÆÓÆ£¡ 
	¾ÆÁîÊ«²ĞÃÎ¶Ï£¬ÄÏ¹úÕıÇå³î¡£ 
	°Ñ½£ÆàÈ»Íû£¬ÎŞ´¦ÕĞ¹éÖÛ¡£ 
 
	Ã÷ÔÂÌìÑÄÂ·Ô¶£¬ÎÊË­Áô³şÅå£¬ÅªÓ°ÖĞÖŞ£¿
	ÊıÓ¢ĞÛ¶ùÅ®£¬¸©Ñö¹Å½ñ³î¡£
	ÄÑÏûÊÜµÆ»èÂŞÕÊ£¬Øöê¼»¨Ò»ÏÖºŞÄÑĞİ£¡
	Æ®Áã¹ß£¬½ğ¸êÌúÂí£¬Æ´Ôá»ÄÇğ£¡ 
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØÊ®¾Å½ïÁùÁ½ÎåÇ®µÄ[1;36mÀ¥ÂØÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;32m¿ªÌìÅüµØ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [32mË®[2;37;0m:[1;31mÎŞË«[2;37;0m [1;35m·ç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌåÁé:[32m´Ö²Ú[2;37;0m °×Ê¯:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[31m¾«ÖÂ[2;37;0m ÖÜÌì:[32m´Ö²Ú[2;37;0m ÍşÁ¦:[31m¾«ÖÂ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mµØÍ¼Ò»ºÅ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÖ¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("ownername", "µØÍ¼Ò»ºÅ");
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
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 18);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1953);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";
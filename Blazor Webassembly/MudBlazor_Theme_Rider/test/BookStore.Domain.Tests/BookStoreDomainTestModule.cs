using BookStore.MongoDB;
using Volo.Abp.Modularity;

namespace BookStore;

[DependsOn(
    typeof(BookStoreMongoDbTestModule)
    )]
public class BookStoreDomainTestModule : AbpModule
{

}

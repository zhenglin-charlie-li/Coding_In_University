using Volo.Abp.Domain.Entities;

namespace TodoAppEntities;

public class TodoItem : BasicAggregateRoot<Guid>
{
    public string Text { get; set; }
}